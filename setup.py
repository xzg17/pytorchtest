from distutils.core import setup, Extension
import os

os.environ['CC'] = 'gcc'

src_dir = 'src'

ext_modules = [Extension('TestMod',[src_dir + '/Test.cpp'])]
ext_modules.append(Extension('BlindBoard',[src_dir + '/BlindBoard.cpp']))
setup(
  name='Test',
  ext_modules = ext_modules,
  url="https://github.com/xzg17/BlindShogi"
)
