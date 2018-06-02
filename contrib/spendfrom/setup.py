from distutils.core import setup
setup(name='ATHspendfrom',
      version='1.0',
      description='Command-line utility for aethercoin "coin control"',
      author='Gavin Andresen',
      author_email='gavin@aethercoinfoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
