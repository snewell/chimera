#include <chimera/job.hpp>

using chimera::Job;

Job::Job(Identifier id, String name)
  : NamedObject{std::move(name)}
  , IdentifiedObject{id}
{
}
