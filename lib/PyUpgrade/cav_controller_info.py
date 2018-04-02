#!/usr/bin/env python
# Name : cav_controller_info.py

HOME_PATH = "/home/netstorm"
MON_BUILD_PATH = "/opt/cavisson"
HPD_BUILD_PATH = "/var"


path = {'bci': 'etc/version',
 'cmon': 'etc/version',
 'gui': 'webapps/netstorm/etc/version',
 'hpd': 'hpd/etc/version',
 'lps': 'lps/etc/version',
 'ndc': 'ndc/etc/version',
 'ns': 'etc/version'}


def get_controllers_as_list():
    controllers = []
    
    with open('/etc/cav_controller.conf') as fp:
	for line in fp:
	    if line.startswith("NAME"):
		continue
	    else:
		controller = line.split('|')[0]
		controllers.append(controller)
    
    return controllers


def get_controller_wise_build_path_as_list(controllers):
    controller_wise_build_path = []
    
    for controller in controllers:
	build_path = {}
	if controller == "work":
	    build_path = {
	    'ns_path' : HOME_PATH + "/" + controller + "/" + path['ns'],
	    'gui_path': HOME_PATH + "/" + controller +  "/" + path['gui'],
	    'bci_path': MON_BUILD_PATH + "/netdiagnostics/" + path['bci'],
	    'cmon_path': MON_BUILD_PATH + "/monitors/" + path['cmon'],
	    'lps_path': HOME_PATH + "/" + controller + "/" + path['lps'],
	    'ndc_path': HOME_PATH + "/" + controller + "/" + path['ndc'],
	    'hpd_path': HPD_BUILD_PATH + "/www/" + path['hpd']
	    }
	else:
	    build_path = {
	    'ns_path' : HOME_PATH + "/" + controller + "/" + path['ns'],
	    'gui_path': HOME_PATH + "/" + controller +  "/" + path['gui'],
	    'bci_path': MON_BUILD_PATH + "/netdiagnostics/" + path['bci'],
	    'cmon_path': MON_BUILD_PATH + "/monitors/" + path['cmon'],
	    'lps_path': HOME_PATH + "/" + controller + "/" + path['lps'],
	    'ndc_path': HOME_PATH + "/" + controller + "/" + path['ndc'],
	    'hpd_path': HPD_BUILD_PATH + "/" + controller + "/" + path['hpd']
	    }

	controller_wise_build_path.append(build_path)

    return controller_wise_build_path


def get_version(path):
    fp = open(path)
    data = fp.read()
    data = data.replace('\n', ' ').strip('Build').split(' ')
    version = data[1]
    build = data[3]

    return "%s_%s" %(version, build)


def main():
    controllers = get_controllers_as_list()
    controller_wise_buid_path = get_controller_wise_build_path_as_list(controllers)

    print "Controller Name|GUI BUILD|HPD BUILD|NDC BUILD|BCI BUILD|LPS BUILD|NS BUILD|CMON BUILD"

    for c, cp in zip(controllers, controller_wise_buid_path):
        print c + "|" + get_version(cp['gui_path']) + "|" + get_version(cp['hpd_path']) + "|" + \
            get_version(cp['ndc_path']) + "|" + get_version(cp['bci_path']) + "|" + \
            get_version(cp['lps_path']) + "|" + get_version(cp['ns_path']) + "|" + get_version(cp['cmon_path'])

main()
