import xml.etree.ElementTree as ET
import sys
import re
from string import Template
from typing import Final

# Constants
PINNAME_MIN_LEN: Final = 3
PINNAME_MAX_LEN: Final = 4
	

# XML parse
tree = ET.parse(sys.argv[1])
root = tree.getroot()
ns   = {'mcu': 'http://mcd.rou.st.com/modules.php?name=mcu'}


# Find all ports
ports = []
for p in root.findall('mcu:GPIO_Port', ns):
    ports.append(p.get('Name')[1])
	
	
# Fill enum class 'Port'
portlist = '\n'
portstr  = "      {name} = GPIO{name}_BASE,\n"
for name in ports:
    portlist = portlist + portstr.format(name = name)



# Fill 'Af' namespace
pinlist = '\n'
pinstr = "      namespace {name} {{ enum {{{fields}}}; }}\n"
afstr  = " {name} = {val}ul, "

for pin in root.findall('mcu:GPIO_Pin', ns):
    name = pin.get('Name')[0:PINNAME_MAX_LEN]
    if len(name) == PINNAME_MIN_LEN:
        name = name + ' '
    elif name.endswith('-') or name.endswith ('_'):
        name = name[:-1] + ' ' 

    fields = ''
    for signal in pin.findall('mcu:PinSignal', ns):
        val = re.findall('(\d+)', signal[0][0].text)[0]
        fields = fields + afstr.format(name = signal.get('Name').replace('-','_'), val = val)
    
    pinlist = pinlist + pinstr.format(name = name, fields = fields)




# Create output file
skeleton = Template(open('skeleton', 'r').read())

filename  = root.get('Version') + '.hpp'
namespace = root.get('Version')
output = open(filename, 'w', encoding='UTF-8')
output.write(skeleton.substitute(filename=filename, namespace=namespace, portlist=portlist, pinlist=pinlist))
output.close()




	
	
