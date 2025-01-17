import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

def func(x, a,b):
    return a * np.square(x) + b


df = pd.read_csv('asgn2_sorting_algorith_analysis\selection_sort_data.txt')

xValue = df['size']
yValue = df['time']

baseInstructionSpeed = 2.6e9
yValue = yValue * baseInstructionSpeed


popt, pcov = curve_fit(func, xValue, yValue)


plt.plot(xValue, yValue, label='Selection Sort', color='b')
plt.plot(xValue, func(xValue, *popt), label='Fitted Curve', color='g')
plt.plot(xValue, np.square(xValue), label='O(n^2)', color='r')
plt.show()