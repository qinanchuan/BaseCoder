#include "BaseCoderTest.hpp"
#include <BaseCoder/BaseCoder.hpp>

namespace base_coder
{
namespace test
{

class Base16CoderTest : public BaseCoderTest
{
protected:
	BaseCoder<Base16Traits> coder;
};

TEST_F(Base16CoderTest, EncodeSize)
{
	auto view = base_coder::View(
			refereceData.begin(), refereceData.end() - 1
	);
	auto encodeView = base_coder::View(
			refereceEncodedDataBase16.begin()
			, refereceEncodedDataBase16.end()
	);

	for (size_t i = 0; i != view.size(); ++i)
	{
		std::string out;
		auto size = coder.encodeSize(view.begin()[i]);
		ASSERT_EQ(encodeView.begin()[i].length(), size);
	}
}

TEST_F(Base16CoderTest, EncodeRfc)
{
	auto view = base_coder::View(
			refereceData.begin(), refereceData.end() - 1
	);
	auto encodeView = base_coder::View(
			refereceEncodedDataBase16.begin()
			, refereceEncodedDataBase16.end()
	);

	for (size_t i = 0; i != view.size(); ++i)
	{
		std::string out;
		coder.encode(view.begin()[i], std::back_inserter(out));
		ASSERT_EQ(encodeView.begin()[i], out);
	}
}

TEST_F(Base16CoderTest, DecodeSize)
{
	auto view = base_coder::View(
			refereceEncodedDataBase16.begin()
			, refereceEncodedDataBase16.end()
	);
	auto decodeView = base_coder::View(
			refereceData.begin(), refereceData.end() - 1
	);

	for (size_t i = 0; i != decodeView.size(); ++i)
	{
		auto size = coder.decodeSize(view.begin()[i]);
		ASSERT_EQ(decodeView.begin()[i].length(), size);
	}
}

TEST_F(Base16CoderTest, DecodeRfc)
{
	auto view = base_coder::View(
			refereceEncodedDataBase16.begin()
			, refereceEncodedDataBase16.end()
	);
	auto decodeView = base_coder::View(
			refereceData.begin(), refereceData.end() - 1
	);

	for (size_t i = 0; i != decodeView.size(); ++i)
	{
		std::string out;
		coder.decode(view.begin()[i], std::back_inserter(out));
		ASSERT_EQ(decodeView.begin()[i], out);
	}
}

}
}
