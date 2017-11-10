#pragma once

// Copyright 2017 Stellar Development Foundation and contributors. Licensed
// under the Apache License, Version 2.0. See the COPYING file at the root
// of this distribution or at http://www.apache.org/licenses/LICENSE-2.0

#include <string>

namespace stellar
{

class Bucket;
class LedgerDelta;

// NOTE: The checkOn* functions should have a default implementation so that
//       more can be added in the future without requiring changes to all
//       derived classes.
class Invariant
{
  public:
    virtual ~Invariant()
    {
    }

    virtual std::string getName() const = 0;

    virtual std::string
    checkOnLedgerClose(LedgerDelta const& delta)
    {
        return std::string{};
    }

    virtual std::string
    checkOnBucketApply(std::shared_ptr<Bucket const> bucket,
                       uint32_t oldestLedger,
                       uint32_t newestLedger)
    {
        return std::string{};
    }
};
}
