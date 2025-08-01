#ifndef icu4x_TimeZoneInfo_HPP
#define icu4x_TimeZoneInfo_HPP

#include "TimeZoneInfo.d.hpp"

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <memory>
#include <functional>
#include <optional>
#include <cstdlib>
#include "../diplomat_runtime.hpp"
#include "IsoDate.hpp"
#include "IsoDateTime.hpp"
#include "Time.hpp"
#include "TimeZone.hpp"
#include "TimeZoneVariant.hpp"
#include "UtcOffset.hpp"
#include "VariantOffsetsCalculator.hpp"


namespace icu4x {
namespace capi {
    extern "C" {

    icu4x::capi::TimeZoneInfo* icu4x_TimeZoneInfo_utc_mv1(void);

    icu4x::capi::TimeZoneInfo* icu4x_TimeZoneInfo_from_parts_mv1(const icu4x::capi::TimeZone* id, const icu4x::capi::UtcOffset* offset, icu4x::capi::TimeZoneVariant_option _variant);

    icu4x::capi::TimeZone* icu4x_TimeZoneInfo_id_mv1(const icu4x::capi::TimeZoneInfo* self);

    icu4x::capi::TimeZoneInfo* icu4x_TimeZoneInfo_at_date_time_iso_mv1(const icu4x::capi::TimeZoneInfo* self, const icu4x::capi::IsoDate* date, const icu4x::capi::Time* time);

    icu4x::capi::TimeZoneInfo* icu4x_TimeZoneInfo_at_timestamp_mv1(const icu4x::capi::TimeZoneInfo* self, int64_t timestamp);

    typedef struct icu4x_TimeZoneInfo_zone_name_date_time_mv1_result {union {icu4x::capi::IsoDateTime ok; }; bool is_ok;} icu4x_TimeZoneInfo_zone_name_date_time_mv1_result;
    icu4x_TimeZoneInfo_zone_name_date_time_mv1_result icu4x_TimeZoneInfo_zone_name_date_time_mv1(const icu4x::capi::TimeZoneInfo* self);

    icu4x::capi::TimeZoneInfo* icu4x_TimeZoneInfo_with_variant_mv1(const icu4x::capi::TimeZoneInfo* self, icu4x::capi::TimeZoneVariant _time_variant);

    icu4x::capi::UtcOffset* icu4x_TimeZoneInfo_offset_mv1(const icu4x::capi::TimeZoneInfo* self);

    typedef struct icu4x_TimeZoneInfo_infer_variant_mv1_result { bool is_ok;} icu4x_TimeZoneInfo_infer_variant_mv1_result;
    icu4x_TimeZoneInfo_infer_variant_mv1_result icu4x_TimeZoneInfo_infer_variant_mv1(icu4x::capi::TimeZoneInfo* self, const icu4x::capi::VariantOffsetsCalculator* _offset_calculator);

    typedef struct icu4x_TimeZoneInfo_variant_mv1_result {union {icu4x::capi::TimeZoneVariant ok; }; bool is_ok;} icu4x_TimeZoneInfo_variant_mv1_result;
    icu4x_TimeZoneInfo_variant_mv1_result icu4x_TimeZoneInfo_variant_mv1(const icu4x::capi::TimeZoneInfo* self);

    void icu4x_TimeZoneInfo_destroy_mv1(TimeZoneInfo* self);

    } // extern "C"
} // namespace capi
} // namespace

inline std::unique_ptr<icu4x::TimeZoneInfo> icu4x::TimeZoneInfo::utc() {
  auto result = icu4x::capi::icu4x_TimeZoneInfo_utc_mv1();
  return std::unique_ptr<icu4x::TimeZoneInfo>(icu4x::TimeZoneInfo::FromFFI(result));
}

inline std::unique_ptr<icu4x::TimeZoneInfo> icu4x::TimeZoneInfo::from_parts(const icu4x::TimeZone& id, const icu4x::UtcOffset* offset, std::optional<icu4x::TimeZoneVariant> _variant) {
  auto result = icu4x::capi::icu4x_TimeZoneInfo_from_parts_mv1(id.AsFFI(),
    offset ? offset->AsFFI() : nullptr,
    _variant.has_value() ? (icu4x::capi::TimeZoneVariant_option{ { _variant.value().AsFFI() }, true }) : (icu4x::capi::TimeZoneVariant_option{ {}, false }));
  return std::unique_ptr<icu4x::TimeZoneInfo>(icu4x::TimeZoneInfo::FromFFI(result));
}

inline std::unique_ptr<icu4x::TimeZone> icu4x::TimeZoneInfo::id() const {
  auto result = icu4x::capi::icu4x_TimeZoneInfo_id_mv1(this->AsFFI());
  return std::unique_ptr<icu4x::TimeZone>(icu4x::TimeZone::FromFFI(result));
}

inline std::unique_ptr<icu4x::TimeZoneInfo> icu4x::TimeZoneInfo::at_date_time_iso(const icu4x::IsoDate& date, const icu4x::Time& time) const {
  auto result = icu4x::capi::icu4x_TimeZoneInfo_at_date_time_iso_mv1(this->AsFFI(),
    date.AsFFI(),
    time.AsFFI());
  return std::unique_ptr<icu4x::TimeZoneInfo>(icu4x::TimeZoneInfo::FromFFI(result));
}

inline std::unique_ptr<icu4x::TimeZoneInfo> icu4x::TimeZoneInfo::at_timestamp(int64_t timestamp) const {
  auto result = icu4x::capi::icu4x_TimeZoneInfo_at_timestamp_mv1(this->AsFFI(),
    timestamp);
  return std::unique_ptr<icu4x::TimeZoneInfo>(icu4x::TimeZoneInfo::FromFFI(result));
}

inline std::optional<icu4x::IsoDateTime> icu4x::TimeZoneInfo::zone_name_date_time() const {
  auto result = icu4x::capi::icu4x_TimeZoneInfo_zone_name_date_time_mv1(this->AsFFI());
  return result.is_ok ? std::optional<icu4x::IsoDateTime>(icu4x::IsoDateTime::FromFFI(result.ok)) : std::nullopt;
}

inline std::unique_ptr<icu4x::TimeZoneInfo> icu4x::TimeZoneInfo::with_variant(icu4x::TimeZoneVariant _time_variant) const {
  auto result = icu4x::capi::icu4x_TimeZoneInfo_with_variant_mv1(this->AsFFI(),
    _time_variant.AsFFI());
  return std::unique_ptr<icu4x::TimeZoneInfo>(icu4x::TimeZoneInfo::FromFFI(result));
}

inline std::unique_ptr<icu4x::UtcOffset> icu4x::TimeZoneInfo::offset() const {
  auto result = icu4x::capi::icu4x_TimeZoneInfo_offset_mv1(this->AsFFI());
  return std::unique_ptr<icu4x::UtcOffset>(icu4x::UtcOffset::FromFFI(result));
}

inline std::optional<std::monostate> icu4x::TimeZoneInfo::infer_variant(const icu4x::VariantOffsetsCalculator& _offset_calculator) {
  auto result = icu4x::capi::icu4x_TimeZoneInfo_infer_variant_mv1(this->AsFFI(),
    _offset_calculator.AsFFI());
  return result.is_ok ? std::optional<std::monostate>() : std::nullopt;
}

inline std::optional<icu4x::TimeZoneVariant> icu4x::TimeZoneInfo::variant() const {
  auto result = icu4x::capi::icu4x_TimeZoneInfo_variant_mv1(this->AsFFI());
  return result.is_ok ? std::optional<icu4x::TimeZoneVariant>(icu4x::TimeZoneVariant::FromFFI(result.ok)) : std::nullopt;
}

inline const icu4x::capi::TimeZoneInfo* icu4x::TimeZoneInfo::AsFFI() const {
  return reinterpret_cast<const icu4x::capi::TimeZoneInfo*>(this);
}

inline icu4x::capi::TimeZoneInfo* icu4x::TimeZoneInfo::AsFFI() {
  return reinterpret_cast<icu4x::capi::TimeZoneInfo*>(this);
}

inline const icu4x::TimeZoneInfo* icu4x::TimeZoneInfo::FromFFI(const icu4x::capi::TimeZoneInfo* ptr) {
  return reinterpret_cast<const icu4x::TimeZoneInfo*>(ptr);
}

inline icu4x::TimeZoneInfo* icu4x::TimeZoneInfo::FromFFI(icu4x::capi::TimeZoneInfo* ptr) {
  return reinterpret_cast<icu4x::TimeZoneInfo*>(ptr);
}

inline void icu4x::TimeZoneInfo::operator delete(void* ptr) {
  icu4x::capi::icu4x_TimeZoneInfo_destroy_mv1(reinterpret_cast<icu4x::capi::TimeZoneInfo*>(ptr));
}


#endif // icu4x_TimeZoneInfo_HPP
