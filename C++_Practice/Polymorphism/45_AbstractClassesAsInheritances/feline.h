#ifndef FELINE_H
#define FELINE_H

#include "animal.h"

class Feline : public Animal {
  public:
    Feline() = default;
    Feline(const std::string_view fur_style, const std::string_view description);
    virtual ~Feline();

    virtual void run() const {
      std::cout << "Feline " << m_description <<" is running." << std::endl;
    }

    virtual void stream_insert( std::ostream& out) const override {
      out << "Feline [ m_fur_style: " << m_fur_style << ", m_description: " << m_description << " ]" << std::endl;
    }

    std::string m_fur_style;
};

#endif