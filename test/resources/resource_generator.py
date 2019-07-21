"""
Generates a set of plots to test the document building of the program.

Author: Mark Xavier
"""

import os
import sys
import random
from argparse import ArgumentParser
import numpy as np
import matplotlib.pyplot as plt

DEFAULT_NUMBER_OF_PLOTS = 10

def plot_histogram(data, index):
    """
    """

    fig, ax = plt.subplots(1, 1)
    ax.hist(data)
    filepath = 'fig_%d_hist.png' % index
    fig.savefig(filepath)

def generate_plots(number_of_plots):
    """
    """

    for index in range(number_of_plots):
        data = np.random.poisson(random.randint(0, 100), 1000)
        plot_histogram(data, index)

def clean_resources_folder():
    """
    """

    directory_tree = os.listdir('./')
    for filename in directory_tree:
        if '.png' in filename:
            os.unlink(filename)

def main():
    """
    """

    parser = ArgumentParser(description='Generate test plots for the DSMC_HTML_Generator.')
    parser.add_argument('-n', '--number-of-plots', type=int, help='The number of plots to generate',
                        default=DEFAULT_NUMBER_OF_PLOTS)
    parser.add_argument('-c', '--clean', action='store_true',
                        help='Simply clears the resources dir.')
    args = parser.parse_args()

    clean_resources_folder()
    if args.clean:
        return 0

    generate_plots(args.number_of_plots)
    return 0

if __name__ == '__main__':
    main()