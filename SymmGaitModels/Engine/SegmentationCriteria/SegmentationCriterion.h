/*
 * SegmentationCriterion.h
 *
 *  Created on: 19-11-2014
 *      Author: Adamek
 */

#ifndef SEGMENTATIONCRITERION_H_
#define SEGMENTATIONCRITERION_H_

namespace Engine {

namespace SegmentationCriteria {

class SegmentationCriterion {
	virtual void dziel() = 0;
	virtual ~SegmentationCriterion() = 0;
};

} // namespace SegmentationCriteria
} /* namespace Engine */
#endif /* SEGMENTATIONCRITERION_H_ */
