#ifndef GAUSSIAN_BLUR_HPP
#define GAUSSIAN_BLUR_HPP

#include "hls_stream.h"

#include "filter.hpp"

template<typename T> T gaussian_blur_f(T data[3][3]) {
	const T filter[3][3] = { { 1, 2, 1 }, { 2, 4, 2 }, { 1, 2, 1 } };
	T res = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res += data[i][j] * filter[i][j];
		}
	}

	res = res / 16;

	return res;
}

template<int ROWS, int COLS, typename T>
void gaussian_blur(hls::stream<T> &src, hls::stream<T> &snk) {
	filter_border3x3<ROWS, COLS>(src, snk, *gaussian_blur_f<T>);
}

#endif //GAUSSIAN_BLUR_HPP
