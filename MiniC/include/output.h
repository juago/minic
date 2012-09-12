#ifndef __OUTPUT__
#define __OUTPUT__

#include <fstream>

class Output
{
public:
    Output(std::string name);
    virtual ~Output() { }

    virtual void write(std::string text) = 0;

protected:
    std::string m_name;
};

class FileOutput : public Output
{
public:
    FileOutput(std::string name);
    ~FileOutput();

    void write(std::string text);

private:
    std::ofstream m_outfile;
};

#endif