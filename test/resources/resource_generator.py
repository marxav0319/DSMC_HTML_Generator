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
import plotly as py
import plotly.graph_objects as go

DEFAULT_NUMBER_OF_PLOTS = 10

def _plot(data, index):
    """Plots a generic histogram of the list of numbers and saves to the resources directory."""

    filepath = 'fig_%d_hist.html' % index
    fig = go.Figure(data=[go.Histogram(x=data)])
    py.offline.plot(fig, filename=filepath)

def generate_plots(number_of_plots):
    """Loops [number_of_plots] times and creates [number_of_plots] histograms."""

    for index in range(number_of_plots):
        data = np.random.poisson(random.randint(0, 100), 1000)
        _plot(data, index)

def clean_resources_folder():
    """Cleans out the resources directory by deleting all created .png files."""

    directory_tree = os.listdir('./')
    for filename in directory_tree:
        if '.png' in filename:
            os.unlink(filename)

def main():
    """The main entrypoint for this script."""

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
