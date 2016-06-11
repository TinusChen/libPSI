#pragma once
#include "Common/Defines.h"
#include "Network/Channel.h"
#include "Crypto/PRNG.h"
#include "OT/OTExtInterface.h"
#include "Common/BitVector.h"


namespace libPSI
{

class AknOtReceiver
{
public:
	AknOtReceiver();
	~AknOtReceiver();

	void init(u64 totalOTCount, u64 numberOfOnes, double p,
		OtExtReceiver& ots, Channel& chl, PRNG& prng)
	{
		std::vector<Channel*> chls{ &chl };
		init(totalOTCount, numberOfOnes, p, ots, chls, prng);
	}


	void init(u64 totalOTCount, u64 numberOfOnes, double p,
		OtExtReceiver& ots, std::vector<Channel*>& chls, PRNG& prng);

	std::vector<u64> mOnes, mZeros;
	std::vector<block> mMessages;
	BitVector mChoices;
};

}