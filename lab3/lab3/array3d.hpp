#pragma once

#include <vector>

using namespace std;

template<typename T>
class array3d {

private:
	vector<T> m_arr;
	int m_dim0, m_dim1, m_dim2;

public:
	array3d(int dim0, int dim1, int dim2) {
		m_dim0 = dim0;
		m_dim1 = dim1;
		m_dim2 = dim2;
	}

	~array3d() {}

	void fill(T data) {
		for (int i = 0; i < m_dim0; ++i) {
			for (int j = 0; j < m_dim1; ++j) {
				for (int k = 0; k < m_dim2; ++k) {
					m_arr.push_back(data);
				}
			}
		}
	}

	void fill_zeros() {
		fill(0);
	}

	void fill_ones() {
		fill(1);
	}

	T getValue(int a, int b, int c) {
		try {
			return m_arr[a * m_dim0 + b * m_dim1 + c];
		}
		catch (const char* error_message) {
			cout << error_message << endl;
		}
		return;
	}

	void setValue(int a, int b, int c, const T& data) {
		try {
			m_arr[a * m_dim0 + b * m_dim1 + c] = data;
		}
		catch (const char* error_message) {
			cout << error_message << endl;
		}
		return;
	}

	void setValue0(vector<vector<T>> data, int a) {
		for (int i = 0; i < )
	}
};