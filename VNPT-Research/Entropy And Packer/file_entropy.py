import math
import os
import matplotlib.pyplot as plt
import sys
from tqdm import tqdm
import matplotlib.pyplot as plt; plt.rcdefaults()

# from multiprocessing import Pool

# def reader(filename):
#     f = open(filename)
#     content = f.read()
#     f.close()
#     return content

def calculate_frequencies(c, byte_array):
	freq = 0
	for ch in byte_array:
		if ch == c:
			freq += 1
	return freq

def calculate_entropy(byte_array):
	entropy = 0
	non_duplicate_byte_array = list(set(byte_array))
	for c in byte_array:
		freq = float(calculate_frequencies(c, byte_array))/len(byte_array)
		entropy += -float(1)/len(byte_array) * (math.log(freq, 2))
		# print float(freq)/len(byte_array)
		# print entropy
	return round(entropy, 1) # round to 1 for plot

# def find_entropy(entropy, entropy_list):
# 	for i in range(0, len(entropy_list)):
# 		if entropy == entropy_list[i]:
# 			return i
# 	return
# def reader_entropy(content):
# 	return calculate_entropy(content)

def mean_med(arr):
	mean = 0
	for i in range(0, len(arr)):
		mean += arr[i]
	mean /= i
	med = arr[i/2]
	return [mean] * len(arr), [med] * len(arr)
 
def main():
	# pool = Pool(2) # number of cores you want to use
	directory = sys.argv[1]
	list_of_files = [os.path.join(directory,f) for f in os.listdir(directory) if os.path.isfile(os.path.join(directory, f))]
	# list_of_files_content = pool.map(reader, list_of_files) #creates a list of the loaded df's
	# entropy_list = pool.map(reader_entropy, list_of_files_content)
	entropy_list = []

	# it should be implemented using panda's multiprocessing but i am just kind of lazy today :)
	for file in tqdm(list_of_files):
		f = open(file)
		content = f.read()
		f.close()
		# byte_array = []
		# for b in content:
		# 	byte_array.append(b)
		entropy_list.append(calculate_entropy(content))
		#sys.stdout.flush()	
	mutual_entropy_list = list(set(entropy_list))
	number_of_files_correspond_to_mutual_entropy_list = []
	for entropy in mutual_entropy_list:
		number_of_files = 0
		for i in range(0, len(entropy_list)):
			if entropy == entropy_list[i]:
				number_of_files += 1
		number_of_files_correspond_to_mutual_entropy_list.append(number_of_files)

	entropy_list = sorted(entropy_list)
	number_of_files_correspond_to_entropy_list = []
	for entropy in entropy_list:
		number_of_files_correspond_to_entropy_list.append(number_of_files_correspond_to_mutual_entropy_list[mutual_entropy_list.index(entropy)])

	fig, ax = plt.subplots()
	mean, med = mean_med(entropy_list)
	data_line = ax.plot(entropy_list, number_of_files_correspond_to_entropy_list, label='Data')
	mean_line = ax.plot(mean, number_of_files_correspond_to_entropy_list, label='Mean', linestyle='--', color='tomato')
	med_line = ax.plot(med, number_of_files_correspond_to_entropy_list, label='Medium', linestyle='--', color='purple')
	# data_line = ax.plot(number_of_files_correspond_to_entropy_list, entropy_list, label='Data')
	# mean_line = ax.plot(number_of_files_correspond_to_entropy_list, mean, label='Mean', linestyle='--', color='tomato')
	# med_line = ax.plot(number_of_files_correspond_to_entropy_list, med, label='Medium', linestyle='--', color='purple')


	plt.xlabel("Entropy")
	plt.ylabel("Number of files")	

	plt.show()	


if __name__ == '__main__':
    main()
