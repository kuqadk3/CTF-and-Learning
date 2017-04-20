#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//
int tri_tuyet_doi(int number){
	if(number < 0){
		return (number*-1);
	}
	return number;
}

vector<int> day_ket_qua_sau_tru(vector<int> number_list){
	vector<int> day_ket_qua_sau_khi_tru;
	for(int i = 0; i < number_list.size(); i += 2){
		day_ket_qua_sau_khi_tru.push_back(tri_tuyet_doi(number_list[i + 1] - number_list[i]));
	}
	return day_ket_qua_sau_khi_tru;
}

int tinh_n_so_cuoi(vector<int> vt_muon_tinh, int number){
	int tong_n_so_cuoi = 0;
	int i = vt_muon_tinh.size() - 1;
	while(number > 0){
		tong_n_so_cuoi += vt_muon_tinh[i];
		i--;
		number--;
	}
	return tong_n_so_cuoi;
}
vector<int> all_possible_sum(vector<int> mang_1, vector<int> mang_2, int number_operator, int so_phep_tinh_cho_phep){
	vector<int> sum_list;
	int so_phep_tinh = 0;
	for(int i = number_operator; i > 0; i--){
		int sum = 0;
		for(int j = 0; j < i; j++) {
			sum += mang_1[j];
		}
		if(i != number_operator){
			int start_point_of_mang_2 = number_operator - i;
			sum += tinh_n_so_cuoi(mang_2, start_point_of_mang_2);
		}
		sum_list.push_back(sum);
		so_phep_tinh++;
		if(so_phep_tinh >= so_phep_tinh_cho_phep) {
			return sum_list;
			break;
		}
	}
	return sum_list;
};

int so_nho_nhat(int so_1, int so_2){
	int so_be_nhat;
	if(so_1 < so_2){
		so_be_nhat = so_1;
	}
	else{
		so_be_nhat = so_2;
	}
	return so_be_nhat;
}
int main(){
	int number_of_student, charisma_value;
	vector<int> charisma_value_list, charisma_value_list_1, charisma_value_list_2;
	cin >> number_of_student;
	
	for(int i = 0; i < number_of_student; i++){
		cin >> charisma_value;
		charisma_value_list.push_back(charisma_value);
	}
	if(number_of_student <= 1){
		cout << 0;
	}
	else{
	//separate in two vector
	for(int i = 0; i < charisma_value_list.size(); i += 2){
		if(i < charisma_value_list.size() - 1){
		charisma_value_list_1.push_back(charisma_value_list[i]);
		charisma_value_list_1.push_back(charisma_value_list[i+1]);
		}
	}
	//
	for(int i = 1; i < charisma_value_list.size(); i += 2){
		if(i < charisma_value_list.size() - 1){
		charisma_value_list_2.push_back(charisma_value_list[i]);
		charisma_value_list_2.push_back(charisma_value_list[i+1]);
		}
	}
	//count from first vector
	vector<int> all_sum_possible, charisma_value_list_1_after_minus, charisma_value_list_2_after_minus;
	charisma_value_list_1_after_minus = day_ket_qua_sau_tru(charisma_value_list_1);
	charisma_value_list_2_after_minus = day_ket_qua_sau_tru(charisma_value_list_2);
	//while(charisma_value_list_1_after_minus.size() < charisma_value_list_2_after_minus.size()){
	//	int real_num = charisma_value_list_1_after_minus.size()
	//	charisma_value_list_1_after_minus.push_back(0);
	//}
	//while(charisma_value_list_2_after_minus.size() < charisma_value_list_1_after_minus.size()){
	//	int real_num = charisma_value_list_2_after_minus.size()
	//	charisma_value_list_2_after_minus.push_back(0);
	//}
	int so_cho_phep = so_nho_nhat(charisma_value_list_1_after_minus.size(), charisma_value_list_2_after_minus.size());
	vector<int> last_list_1 = all_possible_sum(charisma_value_list_1_after_minus, charisma_value_list_2_after_minus, charisma_value_list_1_after_minus.size(), so_cho_phep);
	vector<int> last_list_2 = all_possible_sum(charisma_value_list_2_after_minus, charisma_value_list_1_after_minus, charisma_value_list_2_after_minus.size(), so_cho_phep);
	for(int i = 0; i < last_list_2.size(); i++){
		last_list_1.push_back(last_list_2[i]);
	}
	std::sort(last_list_1.begin() , last_list_1.end());
	cout << last_list_1[last_list_1.size() - 1];
	}
	return 0;
}
