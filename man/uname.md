# uname
By default, the uname utility shall write the operating system name to standard output. When options are specified, symbols representing one or more system characteristics shall be written to the standard output. 

## Usage
```bash
    uname [-amnrsv]
```

## Options
The following options shall be supported:

* `-a`: Behave as though all of the options -mnrsv were specified.
     `
* `-m`: Write the name of the hardware type on which the system is running to standard output.
     `
* `-n`: Write the name of this node within an implementation-defined communications network.
     `
* `-r`: Write the current release level of the operating system implementation.
     `
* `-s`: Write the name of the implementation of the operating system.
     `
* `-v`: Write the current version level of this release of the operating system implementation. 
