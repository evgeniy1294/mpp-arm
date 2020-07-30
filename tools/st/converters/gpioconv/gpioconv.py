import xml.etree.ElementTree as ET
import sys
import re
from string import Template
from typing import Final

# Constants
PINNAME_MIN_LEN: Final = 3
PINNAME_MAX_LEN: Final = 4
RESTRICT = ['PDR_ON', 'PDR_ON_CORE', 'ANA0', 'ANA1', 'PWR_LP', 'PWR_ON']	





# XML parse
#print("Set path to file.xml: ")

tree = ET.parse(sys.argv[1])
root = tree.getroot()
ns   = {'mcu': 'http://mcd.rou.st.com/modules.php?name=mcu'}






# Find all ports
ports = {}
for p in root.findall('mcu:GPIO_Port', ns):
    ports[p.get('Name')[1]] = 0
	
	


	
	
# Fill IO list
pinlist = '\n'
pinstr = '''\n    struct {name} \n    {{
      constexpr inline static auto const Port() noexcept(true) {{ return Port::{portname}; }}
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) {{ return {pinnum}u; }}
      enum {{{fields}}}; \n    }};\n'''
afstr  = " {name} = {val}ul, "

for pin in root.findall('mcu:GPIO_Pin', ns):
    name = pin.get('Name')
    if name in RESTRICT:
        continue
    else:
        name = name[0:PINNAME_MAX_LEN]
	
    if len(name) == PINNAME_MIN_LEN:
        name = name + ' '
    elif name.endswith('-') or name.endswith ('_'):
        name = name[:-1] + ' ' 

    portname = pin.get('PortName')[1] 
    if ports.get(portname) != None:
        ports[portname] = ports[portname] + 1
    else:
        continue

    fields = ''
    for signal in pin.findall('mcu:PinSignal', ns):
        val = re.findall('(\d+)', signal[0][0].text)[0]
        fields = fields + afstr.format(name = signal.get('Name').replace('-','_'), val = val)
    
    pinnum = re.findall(r'\d+', name)[0]
    pinlist = pinlist + pinstr.format(name = name, fields = fields, portname = portname, pinnum = pinnum)



	
	
	
#Fill 'pincheck' field
pincheck = '\n'
checkstr = '        case Port::{port}: return IO::Pin() < {val}u;\n'
for key in ports:
    if ports[key] != 0:
        pincheck = pincheck + checkstr.format(port = key, val = ports[key])



		
		
		
		
# Fill enum class 'Port'
portlist = '\n'
portstr  = "      {name} = GPIO{name}_BASE,\n"
for key in ports:
    if ports[key] != 0:
        portlist = portlist + portstr.format(name = key)
	
	
	
	
	
	
	
# Create output file
skeleton = Template(open('skeleton', 'r').read())

filename  = root.get('Version') + '.hpp'
namespace = root.get('Version')
output = open(filename, 'w', encoding='UTF-8')
output.write(skeleton.substitute(filename=filename, namespace=namespace, portlist=portlist, pincheck = pincheck, pinlist=pinlist))
output.close()


print(ports)

	
	
