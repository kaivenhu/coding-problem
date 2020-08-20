#!/bin/sh

number=${1}
raw_name=${2}
namespace=${3}

makefilesrc="leetcode/problems/0-example/Makefile"
name="`echo ${raw_name} | sed -r 's/ /-/g' | tr [A-Z] [a-z]`"
dirname="leetcode/problems/${number}-${name}"
header="${name}.h"
headerfile="${dirname}/${header}"
makefile="${dirname}/Makefile"
headerdefine="`echo ${name} | sed -r 's/-/_/g' | tr [a-z] [A-Z]`_H_"
srcfile="${dirname}/${name}.cc"
unittestfile="${dirname}/${name}-unittest.cc"

if [ -z "${number}" ] || [ -z "${name}" ] || [ -z "${namespace}" ]; then
    echo "Usage: ${0} number name namespace"
    exit 1
fi

if [ -d "${dirname}" ]; then
    echo "This problem ${dirname} is already exist"
    exit 1
fi

mkdir "${dirname}"
if [ "0" -ne "$?" ]; then
    echo "Failed to create ${dirname}"
    exit 1
fi

if [ ! -f "${makefilesrc}" ]; then
    echo "Failed to get makefile src"
    exit 1
fi

cp -rf "${makefilesrc}" "${makefile}"
if [ "0" -ne "$?" ]; then
    echo "Failed to copy ${makefile}"
    exit 1
fi

# Create header file
echo "Create ${headerfile} with namespace ${namespace} and define ${headerdefine}"
echo -n "#ifndef ${headerdefine}\n#define ${headerdefine}\n\nnamespace ${namespace}\n{\n\n\n}  // namespace ${namespace}\n\n#endif /* ${headerdefine} */\n" >> ${headerfile}

# Create src file
echo "Create ${srcfile} with namespace ${namespace}"
echo -n "#include \"${header}\"\n\nnamespace ${namespace}\n{\n\n\n}  // namespace ${namespace}\n" >> ${srcfile}

# Create unittest file
echo "Create ${unittestfile} with namespace ${namespace}"
echo -n "#include <gtest/gtest.h>\n\n#include \"${header}\"\n\nusing namespace ${namespace};\n\n" >> ${unittestfile}
echo -n "TEST(${namespace}, basic)\n{\n}\n\n" >> ${unittestfile}
echo -n "int main(int argc, char **argv)\n{\n    ::testing::InitGoogleTest(&argc, argv);\n    return RUN_ALL_TESTS();\n}\n" >> ${unittestfile}
