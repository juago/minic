#include <output.h>

Output::Output(std::string name)
    : m_name(name)
{
}

FileOutput::FileOutput(std::string name)
    : Output(name)
{
    m_outfile.open(m_name);
}

FileOutput::~FileOutput()
{
    m_outfile.close();
}

void FileOutput::write(std::string text)
{
    m_outfile.write(text.c_str(), text.length());
}