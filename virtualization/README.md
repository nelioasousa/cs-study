# Summary
Virtualization is used to reach software isolation in a single machine. There are two main ways of virtualization: virtual machines (VMs) and containerization. In VMs, the isolation is in the hardware level, where hardware components are virtually segmented to create multiple virtual machines from a single physical machine, where each VM functions as a independent computer. Containerization on the other hand, implements isolation of applications in a single physical machine using the operating system fetures to do that. Each container packs all the resources of an application (code, dependencies, data, memory space, network space, processes, and others) and is isolated from the other containers.

The underling software that implements virtual machines is know as hypervisor. The are two types of hypervisor: type 1 and type 2. The former is build on top of the hardware in direct contact with it. In the latter, an operating system, the host OS, is between the hardware and the hypervisor. In both cases, each virtual machine has its own OS instance. For type 2 hypervisors, the VMs' OS instances are know as guest OSs and can be different from the host OS instance.

Back to containerization again, the software that manages the lifecycle of all containers in a machine is the Docker Engine, responsable for allocating and releasing the OS resources that each container needs. The isolation in reached using the cgroups and namespace features of the Linux kernel.

Sources: 
- [Virtual Machine (VM) vs Docker](https://youtu.be/a1M_thDTqmU?si=xUo-NGJB-7gq2qpq)
- [What is a Hypervisor?](https://youtu.be/LMAEbB2a50M?si=s4UKltABQNWSq4oa)
