#ifndef MATRIX_IO_H
#define MATRIX_IO_H

#include "../blockbase.h"
#include "../graph.h"

class MatrixInput : public BlockBase
{
public:
	MatrixInput(Graph &g);
	void Compute() override;
	virtual ~MatrixInput() = default;
};

class MatrixOutput : public BlockBase
{
public:
	MatrixOutput(Graph &g);
	void Compute() override;
	virtual ~MatrixOutput() = default;
};


#endif // MATRIX_IO_H