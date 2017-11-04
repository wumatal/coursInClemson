import geni.portal as portal
import geni.rspec.pg as RSpec
import geni.rspec.igext

pc = portal.Context()

pc.defineParameter( "n", "Number of slave nodes",
		    portal.ParameterType.INTEGER, 3 )

pc.defineParameter( "raw", "Use physical nodes",
                    portal.ParameterType.BOOLEAN, False )

pc.defineParameter( "mem", "Memory per VM",
		    portal.ParameterType.INTEGER, 256 )

params = pc.bindParameters()

IMAGE = "urn:publicid:IDN+emulab.net+image+emulab-ops//hadoop-273"
SETUP = "http://www.emulab.net/downloads/hadoop-2.7.3-setup.tar.gz"

def Node( name, public ):
    if params.raw:
        return RSpec.RawPC( name )
    else:
        vm = geni.rspec.igext.XenVM( name )
        vm.ram = params.mem
        if public:
            vm.routable_control_ip = True
        return vm

rspec = RSpec.Request()

lan = RSpec.LAN()
rspec.addResource( lan )


'''
node = Node( "namenode", True )
node.disk_image = IMAGE
node.addService( RSpec.Install( SETUP, "/tmp" ) )
node.addService( RSpec.Execute( "sh", "sudo /tmp/setup/hadoop-setup.sh" ) )
iface = node.addInterface( "if0" )
lan.addInterface( iface )
rspec.addResource( node )

node = Node( "resourcemanager", True )
node.disk_image = IMAGE
node.addService( RSpec.Install( SETUP, "/tmp" ) )
node.addService( RSpec.Execute( "sh", "sudo /tmp/setup/hadoop-setup.sh" ) )
iface = node.addInterface( "if0" )
lan.addInterface( iface )
rspec.addResource( node )

for i in range( params.n ):
    node = Node( "slave" + str( i ), False )
    node.disk_image = IMAGE
    node.addService( RSpec.Install( SETUP, "/tmp" ) )
    node.addService( RSpec.Execute( "sh", "sudo /tmp/setup/hadoop-setup.sh" ) )
    iface = node.addInterface( "if0" )
    lan.addInterface( iface )
    rspec.addResource( node )
'''

# Yupeng's work
nodes = dict()
nodes['namenode'] = True
nodes['resourcemanager'] = True
for i in range( params.n ):
	nodes["slave" + str( i )] = False

for key, value in nodes.iteritems():
    node = Node( key, value )
    node.disk_image = IMAGE
    node.addService( RSpec.Install( SETUP, "/tmp" ) )
    node.addService( RSpec.Execute( "sh", "sudo /tmp/setup/hadoop-setup.sh" ) )
    node.addService( RSpec.Execute(shell="/bin/sh",
                                  command="sudo apt-get install zookeeper"))
    iface = node.addInterface( "if0" )
    lan.addInterface( iface )
    rspec.addResource( node )

# end of Yupeng's work

from lxml import etree as ET

tour = geni.rspec.igext.Tour()
tour.Description( geni.rspec.igext.Tour.TEXT, "A cluster running Hadoop 2.7.3. It includes a name node, a resource manager, and as many slaves as you choose." )
tour.Instructions( geni.rspec.igext.Tour.MARKDOWN, "After your instance boots (approx. 5-10 minutes), you can log into the resource manager node and submit jobs.  [The HDFS web UI](http://{host-namenode}:50070/) and [the resource manager UI](http://{host-resourcemanager}:8088/) will also become available." )
rspec.addTour( tour )

pc.printRequestRSpec( rspec )
