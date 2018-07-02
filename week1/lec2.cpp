06/28/2018

Lec 2:
OS Services:
-generally offered as absstractions
-basic categories:
	*CPU / Memory absstractions
		-processes, threads, virtual machines
		-virtual address spaces, shared segments.
	*Persisten storage absstractions:
		-file and file systems
	*Other I/O abstractions:
		- virtual terminal sessions, windows
		- sockets, pipes, VPNs, signals (as interrupts)


Services: Higher level abstractions
*Cooperating parallel processes:
	-locks, condition variables,
	-distributed transactions, leases

*security:
	- user authentication
	- secure sessions, at - rest encryption

*user interface:
	-GUI widgets, desktop and window management
	-multi- media

Services under the covers:
*not directly visible to users
*enclosure management:
	-hot-plug, power, fans, fault handling

* software update and configuration registry
*dynamic resource and allocation and scheduling
	-CPU, memory, bus resources, disk, network

*networks, protocols, and domain services:
	-USB, bluetooth
	-TCP/IP, DHCP, LDAP, SNMP.
	-iSCSI, CIFS, NFS

Software Layering:
(user and system) applications
operating system services / middleware services
----------------------application binary interface
general libraries
drivers / operating system kernel
---------------------- instruction set architecture

devices/ privileged instruction set / general instruction set





2.How can the OS deliver these services:

*several possible ways:
	-applications could just call subroutines
	-applications could make system calls
	-applications could send message to software that performs the services

*each option works at a different layer of the stack software


3. OS layering:
* modern OSes offer services via layers of software and hardware
* higer level abstract services offered at high software layers
* lower level abstract services offered deeper in the OS
* everything mapped down to hardware


4. services delivery via subroutines:
*access services via direct subroutines calls:
	-push parameters, jump to subroutine, return values in registers on the stack
*typically at high layers
*advantages:
	-extremely fast 
	-run-time implementation binding possible
*disadvantages:
	-all services implemented in same address space
	-limited ability to combine different languages
	-can't usually use privileged instructions

5. service delivery via Libraries:
*one subroutine service delivery approach

*programmers do not need to write all code for programs:
	-standard utility functions can be found in Libraries

*a library is a collection of object modules:
	-a single file that contains many files 
	- these modules can be used directly, w/o recompilation

* most systems come with many standard Libraries:
	-system services, encryption, statistics
	-additional libraries may come with add-on products

*programmers can build their own libraries
*disadvantages: cannot do privileged instruction

5. The library layer
(user and system) applications
operating system services / middleware services
----------------------application binary interface
general libraries
drivers / operating system kernel
---------------------- instruction set architecture

devices/ privileged instruction set / general instruction set


6. Characteristics of libraries:

*many advantages:
	-reusable code makes programming easier
	-a single well written/maintained copy
	-encapsulates complexity ..better building blocks

* multiple bind-time options:
	static .. include in load module at link bind-time
	shared ... map into address space at exec time
	dynamic ... choose and load at run time
Recall that libraries are only code it has no special privileges



7. Shared libraries:
*static library modules are added to a program's load module
- each load module has its own copy of each library:
	*increase the size of each process
- program must be re-linked to incorporate new library:
	*existing load modules don't benefit from bug fixes

*instead, make each library a sharable code segment:
	-one in-memory copy, shared by all process


8. Advantages of shared libraries:
-reduced memory consumption
-faster program startup
simplified updates

Disadvantages:
-not all modules will work: they cannot define global data storage
-they must have to be added program memory whether needed or not

....