#pragma once

#include <string>
#include <vector>
#include <cstdarg>
#include <ostream>
#include <memory>



class Code {
public:
	Code() = default; 
	Code(std::vector<int> _code) : _codeData(_code) {}
	~Code() = default;
	
	[[nodiscard]] size_t getSize() const { return _codeData.size(); };

	int getDigitAt(const size_t n) const;

	friend std::ostream& operator<<(std::ostream& os, const Code& ct);
private:
	std::vector<int> _codeData;
};

typedef std::shared_ptr<Code> CodePtr;