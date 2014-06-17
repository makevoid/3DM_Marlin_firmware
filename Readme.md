# Marlin firmware
### Tuned for 3DM1 RepRap 3d printer by 3DMaking


### Main changes:

- Reduced default acceleration and max speed (3DM1 printer doesn't have a triangular support for Y vibrations)
- Added resistor values (todo: make condition from rrw resistor to heater cartridge, both suppliers)
- todo: Make and add thermistor tables
- todo: add LCD / SD module
- todo: make 3DM2 condition (different size and increased speeds/accelerations)

### Recommended Cura/Slicer settings

for default 0.35mm nozzle

- layer height: 0.27 (fast) 0.2 (good), 0.15 (fine),  0.10 (finest) mm
- speed: 55mm/sec (good), 70-100 mm/sec (big and circular pieces and abs print faster)
- infill speed: 65mm/sec (good), 80mm/sec (warning: may cause vibrations)
- minimum recommended infill: 15% (0% for vases is still ok though :) )
- maximum recommended infill: 55% (we print 3d printer parts at this percentage)
- temp: depends on the material (we use 220 for PLA and 240 for ABS)
- bottom/top infill: 3-4 times the layer height
- shell thickness: 2-3 times the nozzle size
- retraction: speed: 30, distance: 2.5


Cura and Slic3r profiles will be uploaded soon



3DMaking: <http://3dmaking.it>
"You thought it? Let's 3D make it!"


to see the Marlin readme open: Marlin_readme.md
