#include "Stage.h"

Stage::Stage(const std::string& name) : name(name), startDate(1,1,2026),endDate(31,12,2026), status(StageStatus::Planned)
{
}

std::ostream& operator<<(std::ostream& os, const Stage& stage)
{
    os << stage.name << ' ' << stage.startDate << ' ' << stage.endDate << ' ' << stageStatusToString(stage.status) << std::endl;
    return os;
}
