#include "sample_multijittered.h"
#include "drand48.h"

Sample_MultiJittered::Sample_MultiJittered(const int num_samples, const int num_sets)
	:Sampler(num_samples, num_sets)
{
	generate_samples();
}

void Sample_MultiJittered::generate_samples()
{
	std::vector<int> gridNums;
	std::vector<int> blockNums;
	int gridIndex, gridNum, blockIndex, blockNum;
	int gridRow, gridCol, blockRow, blockCol;
	int n = (int)sqrt(num_samples);
	int u, v;

	for (int k = 0; k != num_sets; ++k)
	{
		gridNums.clear();
		blockNums.clear();
		for (int num = 0; num != num_samples; ++num) {
			gridNums.push_back(num);
			blockNums.push_back(num);
		}
		for (int i = 0; i != num_samples; ++i) {
			gridIndex = int(drand48()*gridNums.size());
			gridNum = gridNums[gridIndex];
			gridNums.erase(gridNums.begin() + gridIndex);
			gridRow = gridNum % n;
			gridCol = gridNum / n;

			blockIndex = int(drand48()*blockNums.size());
			blockNum = blockNums[blockIndex];
			blockNums.erase(blockNums.begin() + blockIndex);
			blockRow = blockNum % n;
			blockCol = blockNum / n;

			u = int(gridRow*n + blockRow + drand48()) / num_samples;
			v = int(gridCol*n + blockCol + drand48()) / num_samples;

			samples.push_back(Vec2(u,v));
		}
	}
}
