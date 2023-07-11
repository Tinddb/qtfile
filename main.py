import subprocess
import pkgutil
import sys
import os

def install_packages(package_list):
    for package in package_list:
        if pkgutil.find_loader(package) is not None:
            print('\nPackage ' + package + ' is already installed!')
        else:
            with open(os.devnull, 'w') as devnull:
                exit_code = subprocess.call(['apt-get', 'install', '-y', package], stdout=devnull, stderr=subprocess.STDOUT)
            if exit_code == 0:
                print('\nPackage ' + package + ' was successfully installed!')
            else:
                print('\nFailed to install package ' + package)
                sys.exit(1)


def main():
    if os.getuid() == 0:
        with open('list_package.txt', 'r') as f:
            package_list = [line.strip() for line in f.readlines()]
        with open(os.devnull, 'w') as devnull:
            subprocess.call(['apt', 'update'], stdout=devnull, stderr=subprocess.STDOUT)
            subprocess.call(['apt-get', 'upgrade', '-y'], stdout=devnull, stderr=subprocess.STDOUT)
        install_packages(package_list)
    else:
        print('User is not an administrator.')


if __name__ == '__main__':
    main()