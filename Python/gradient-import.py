#!/usr/local/bin/python

import urllib2, svgelements, re, sys
from xml.dom import minidom

# TODO: Add pareser for svg clipboard template with style="stop-color:#F4A830"

py_name="gradient-import.py"
py_description="Importing gradient files from SVG by URL.\nPreferably get the SVG files from here: http://soliton.vm.bytemark.co.uk/pub/cpt-city/"

# helper for showing help information
def ShowHelp():
    print(py_description)
    print('  Usage: ./'+py_name+' [url]')

# we need at least the URL
if (len(sys.argv) < 2):
    ShowHelp()
    sys.exit()

url = sys.argv[1]
doc_name = url.split('/')[-1].split('.')[:-3][0]
svg_url = '/'.join(url.split('/')[:-2]) + '/' + doc_name + '.svg'
svg_data = urllib2.urlopen(svg_url)
svg = minidom.parse(svg_data)
linearGradient = svg.getElementsByTagName('linearGradient')[0]

colors = []
for stop in svg.getElementsByTagName('linearGradient')[0].getElementsByTagName('stop'):
	offset=stop.getAttribute('offset')
	offset=int((float(offset.strip('%'))/100 if '%' in offset else offset)*255)
	if stop.hasAttribute("style"):
		rgb=[0,0,0]
	else:
		rgb=list(re.findall(r"(\d+),\s*(\d+),\s*(\d+)", stop.getAttribute('stop-color'))[0])
		rgb=[int(item) for item in rgb]
	colors.append([offset] + rgb)

sorted(colors, key=lambda x: x[0], reverse=False)
c_string = "{\n"
c_string += "\t/**\n"
c_string += "\t * "+doc_name+"\n"
c_string += "\t * url: "+url+"\n"
c_string += "\t */\n\t"
c_string += ",\n\t".join("{"+", ".join(str(num) for num in sub)+"}" for sub in colors)
c_string += "\n}"
print c_string