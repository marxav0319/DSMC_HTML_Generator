"""
Generates a test input file using the .png files located in the resources directory.

Author: Mark Xavier
"""

import os

def generate_test_input():
    """Generates a single test input file using the images in the resources directory"""

    directory = os.listdir('../resources')
    f = open('test_input.txt', 'w')
    index = 0
    for filename in directory:
        if '.html' in filename:
            full_path = os.path.abspath(os.path.join('../resources', filename))
            f.write('%d %s Header | %s\n' % (index, filename, full_path))
            index += 1
    f.close()

if __name__ == '__main__':
    generate_test_input()
