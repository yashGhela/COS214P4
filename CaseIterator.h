#ifndef CASEITERATOR_H
#define CASEITERATOR_H

class CaseComponent;

class CaseIterator {
    public:
        virtual ~CaseIterator() = default; 
        virtual CaseComponent* first() = 0;
        virtual CaseComponent* next() = 0;
        virtual bool hasNext() = 0;
        virtual CaseComponent* current() = 0;
};


#endif