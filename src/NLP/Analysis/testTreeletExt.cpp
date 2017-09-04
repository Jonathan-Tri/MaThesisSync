/*
 * testTreeletExt.cpp
 *
 *  Created on: Sep 1, 2017
 *      Author: jonathan.tri.vo
 */

#include <string>
#include <vector>

#include "../../SharedAlgorithm/logging.h"
#include "../Alignment/AlignedSentence.h"
#include "../ParsedTree/ParserTree.h"
#include "TreeletExt.h"

/*
 * Test the treelet extraction algorithm
 */

TreeletExt treeletExtAlg;

void testTreeletExt1(ParserTree ptree, AlignedSentence algsent) {
	treeletExtAlg.addMessage("***Test Treelet Extraction Algorithm****");
	logging::logFatal("***Test Treelet Extraction Algorithm****");

	treeletExtAlg.setTree(ptree);
	treeletExtAlg.setAlgSent(algsent);

	treeletExtAlg.addMessage("The source parsed tree: ");
	treeletExtAlg.addMessage(ptree.traversal());
	logging::logFatal("[testTreeletExt1]: The source parsed tree: %s", ptree.traversal().c_str());
	std::string srcSent = "";
	for (int i = 0; i < algsent.SrcSent.size(); i++) {
		srcSent += algsent.SrcSent[i];
	}
	treeletExtAlg.addMessage("SrcSent: " + srcSent);
	logging::logFatal("[testTreeletExt1]: SrcSent: %s", srcSent.c_str());
	std::string tgtSent = "";
	for (int i = 0; i < algsent.TgtSent.size(); i++) {
		tgtSent += algsent.TgtSent[i];
	}
	treeletExtAlg.addMessage("TgtSent: " + tgtSent);
	logging::logFatal("[testTreeletExt1]: TgtSent: %s", tgtSent.c_str());

	logging::logFatal("--->>Running...");
	treeletExtAlg.execute();
	logging::logFatal("Finish!!!");
}

