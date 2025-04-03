import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/robogames/vt-cro/robogames_pi/install/opencv_tools'
