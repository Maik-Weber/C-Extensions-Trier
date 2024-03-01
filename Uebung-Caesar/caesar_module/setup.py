from distutils.core import setup, Extension

def main():
    setup(name="caesar_module",
          version="1.0.0",
          description="Python interface for Ceasar Encryption implemented in C",
          ext_modules=[Extension("caesar_module", ["caesar.c"])])

if __name__ == "__main__":
    main()