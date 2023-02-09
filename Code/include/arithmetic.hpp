#ifndef ARITHMETIC_HPP
#define ARITHMETIC_HPP

#include "hls_math.h"
#include "hls_stream.h"

#include "filter.hpp"

template<typename T>
void difference(hls::stream<T> &src1, hls::stream<T> &src2,
		hls::stream<T> &snk) {
#pragma HLS PIPELINE II=1 style=flp
	snk.write(src1.read() - src2.read());
}

template<typename T>
void sum(hls::stream<T> &input1, hls::stream<T> &input2, hls::stream<T> &output) {
#pragma HLS PIPELINE II=1 style=flp
	output.write(input1.read() + input2.read());
}

#endif //ARITHMETIC_HPP
