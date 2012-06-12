//============================================================================
//                                  I B E X                                   
// File        : ibex_ParserNumConstraint.h
// Author      : Gilles Chabert
// Copyright   : Ecole des Mines de Nantes (France)
// License     : See the LICENSE file
// Created     : Jun 12, 2012
// Last Update : Jun 12, 2012
//============================================================================

#ifndef __IBEX_PARSER_NUM_CONSTRAINT_H__
#define __IBEX_PARSER_NUM_CONSTRAINT_H__

#include "ibex_ParserGenerator.h"
#include "ibex_NumConstraint.h"

namespace ibex {

namespace parser {

class P_NumConstraint {
public:
	P_NumConstraint();
	virtual void acceptVisitor(P_Generator& g) const;
	virtual ~P_NumConstraint();
};

class P_OneConstraint : public P_NumConstraint {
public:
	P_OneConstraint(const ExprNode& expr, NumConstraint::CompOp op);

	void acceptVisitor(P_Generator& g) const {
		g.visit(*this);
	}

	const ExprNode& expr;
	NumConstraint::CompOp op;
};

class P_ConstraintLoop : public P_NumConstraint {
public:
	P_ConstraintLoop(const char* iter, int first_value, int last_value, const P_NumConstraint& ctr);

	void acceptVisitor(P_Generator& g) const {
		g.visit(*this);
	}

	const char* iter;
	int first_value;
	int last_value;
	const P_NumConstraint& ctr;

};

} // end namespace parser
} // end namespace ibex
#endif // __IBEX_PARSER_NUM_CONSTRAINT_H__
