#include "sample_nrooks.h"
#include "drand48.h"

Sample_NRooks::Sample_NRooks(const int num_samples, const int num_sets)
	:Sampler(num_samples, num_sets)
{
	generate_samples();
}

void Sample_NRooks::generate_samples()
{
	std::vector<int> rowNums;
	std::vector<int> colNums;
	int colNum, rowNum, colIndex, rowIndex;

	for (int k = 0; k != num_sets; ++k)
	{
		rowNums.clear();
		colNums.clear();
		for (int num = 0; num != num_samples; ++num) {
			rowNums.push_back(num);
			colNums.push_back(num);
		}
		for (int i = 0; i != num_samples; ++i) {
			rowIndex = int(drand48()*rowNums.size());
			rowNum = rowNums[rowIndex];
			rowNums.erase(rowNums.begin() + rowIndex);

			colIndex = int(drand48()*colNums.size());
			colNum = colNums[colIndex];
			colNums.erase(colNums.begin() + colIndex);

			Vec2 sp((rowNum + drand48()) / num_samples, (colNum + drand48()) / num_samples);
			samples.push_back(sp);
		}
	}
}