import geni.portal as portal
import geni.rspec.pg as RSpec
import geni.rspec.igext
import socket

pc = portal.Context()

pc.defineParameter( "n", "Number of slave nodes",
		    portal.ParameterType.INTEGER, 3 )

#pc.defineParameter( "raw", "Use physical nodes", portal.ParameterType.BOOLEAN, False )

#pc.defineParameter( "mem", "Memory per VM", portal.ParameterType.INTEGER, 256 )

pc.defineParameter("i", "OS: 0 is Ubuntu 14.04; 1 is Centos 7.1", portal.ParameterType.INTEGER, 1)

params = pc.bindParameters()

rspec = RSpec.Request()

# Check parameter validity
if params.n < 3 or params.n > 96:
    perr = portal.ParameterError( "You must choose from 3 to 96", ['n'])
    pc.reportError(perr)

# Check parameter for image
if params.i == 0:
    IMAGE = "urn:publicid:IDN+emulab.net+image+emulab-ops:UBUNTU14-64-STD"
else:
    IMAGE = "urn:publicid:IDN+emulab.net+image+emulab-ops:CENTOS7-64-STD"

#IMAGE = "urn:publicid:IDN+emulab.net+image+emulab-ops//hadoop-273"
DOWNLOAD = "https://github.com/ifding/hadoopOnGeni/raw/master/download.tar.gz"

lan = RSpec.LAN()
rspec.addResource( lan )

# Yupeng's work
#hostnames = []
#nodes = []

#name node
node = RSpec.RawPC( "namenode" )
node.disk_image = IMAGE
#node.hardware_type = "c8220x"
node.addService(RSpec.Install( DOWNLOAD, "/tmp" ))
#node.addService(RSpec.Execute(shell="/bin/sh", command="sh /tmp/download.sh"))
#print('download finished')
node.addService(RSpec.Execute(shell="/bin/sh", command="wget https://github.com/ifding/hadoopOnGeni/archive/master.zip -O hadoopOnGeni.zip"))
node.addService(RSpec.Execute(shell="/bin/sh", command="unzip hadoopOnGeni.zip -d /tmp"))
node.addService(RSpec.Execute(shell="/bin/sh", command="mv /tmp/hadoopOnGeni-master/ /tmp/hadoopOnGeni"))
node.addService(RSpec.Execute(shell="/bin/sh", command="rm hadoopOnGeni.zip"))
#print('install started')
node.addService(RSpec.Execute(shell="/bin/sh", command="sh /tmp/hadoopOnGeni/install.sh"))
iface = node.addInterface( "if0" )
lan.addInterface( iface )
rspec.addResource( node )
#nodes.append(node)
#print(nodes)
#hostnames.append(socket.gethostname())

#resource manager
node = RSpec.RawPC( "resourcemanager")
node.hardware_type = "c8220"
node.disk_image = IMAGE
node.addService(RSpec.Install( DOWNLOAD, "/tmp" ))
node.addService(RSpec.Execute(shell="/bin/sh", command="sh /tmp/download.sh"))
node.addService(RSpec.Execute(shell="/bin/sh",
                                  command="sh /tmp/hadoopOnGeni/install.sh"))
iface = node.addInterface( "if0" )
lan.addInterface( iface )
rspec.addResource( node )

#slave node
for i in range( params.n ):
    node = RSpec.RawPC( "slave" + str( i ))
    #node.hardware_type = "c8220"
    node.disk_image = IMAGE
    node.addService(RSpec.Install( DOWNLOAD, "/tmp" ))
    node.addService(RSpec.Execute(shell="/bin/sh", command="sh /tmp/download.sh"))
    node.addService(RSpec.Execute(shell="/bin/sh",
                                  command="sh /tmp/hadoopOnGeni/install.sh"))
    iface = node.addInterface( "if0" )
    lan.addInterface( iface )
    rspec.addResource( node )

#for i in iter(nodes):
#    print(hostnames)
    #node.addService(RSpec.Execute(shell="/bin/sh", command="cat %s > hostnames.txt"%str(hostnames)))

from lxml import etree as ET

tour = geni.rspec.igext.Tour()
tour.Description( geni.rspec.igext.Tour.TEXT, "A cluster running Hadoop 2.7.3. It includes a name node, a resource manager, and as many slaves as you choose." )
tour.Instructions( geni.rspec.igext.Tour.MARKDOWN, "After your instance boots (approx. 5-10 minutes), you can log into the resource manager node and submit jobs.  [The HDFS web UI](http://{host-namenode}:50070/) and [the resource manager UI](http://{host-resourcemanager}:8088/) will also become available." )
rspec.addTour( tour )

pc.printRequestRSpec( rspec )
