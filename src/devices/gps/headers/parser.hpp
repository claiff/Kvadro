//
// Created by claiff on 9/18/21.
//

#pragma once

#include <string>
#include <vector>
#include "types/iparser.hpp"

namespace device::gps::headers
{
  class Parser : public types::IParser
  {
  public:
	Parser( std::string const& field, uint8_t count_field );
	void ProcessData( uint8_t data ) override;
	[[nodiscard]] std::string GetField( uint8_t number ) const override;
  private:
	bool FindHeader();
	[[nodiscard]] bool IsEnoughData() const;
	[[nodiscard]] unsigned int GetHeaderPosition() const;
	void ClearOnPosition( uint8_t position );
	[[nodiscard]] uint8_t GetCountFields() const;
	void ParseData();

	std::string mField;
	uint8_t mCountField;
	bool mIsFound;
	std::string mData;
	std::vector<std::string> mParsedData;

  };

}