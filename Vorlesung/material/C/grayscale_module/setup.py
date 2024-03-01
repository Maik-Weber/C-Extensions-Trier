from distutils.core import setup, Extension

def main():
    setup(name="grayscale_module",
          version="1.0.0",
          description="Python interface for Grayscale Filter Functionality",
          ext_modules=[Extension("grayscale_module", ["grayscale.c"])])

if __name__ == "__main__":
    main()