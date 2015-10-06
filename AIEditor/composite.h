#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <QTextStream>

#include "node.h"

class Composite : public Node
{
public:
    Composite(Node *parent = 0) : Node(parent) {}
    Composite(const QMap<QString, QVariant> &data, Node *parent = 0)
        : Node(data, parent) {}
    virtual ~Composite() {}

    QTextStream& write(QTextStream& stream) const
    {
        stream << "\t{\"" << id().toString()
               << "\", \"" << "Composite"
               << "\", \"" << parentID().toString();
        if (name().toString() == "Sequence")
            stream << "\", SEQUENCEBEHAVIOR},\n";
        else if (name().toString() == "Selector")
            stream << "\", SELECTORBEHAVIOR},\n";

        return Node::write(stream);
    }

private:
};

#endif // COMPOSITE_H