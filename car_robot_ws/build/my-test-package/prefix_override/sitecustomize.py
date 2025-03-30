import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/robogames/vt-cro/robogames_pi/car_robot_ws/install/my-test-package'
