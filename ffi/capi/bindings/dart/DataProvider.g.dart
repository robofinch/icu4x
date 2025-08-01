// generated by diplomat-tool
// dart format off

part of 'lib.g.dart';

/// An ICU4X data provider, capable of loading ICU4X data keys from some source.
///
/// Currently the only source supported is loading from "blob" formatted data from a bytes buffer or the file system.
///
/// If you wish to use ICU4X's builtin "compiled data", use the version of the constructors that do not have `_with_provider`
/// in their names.
///
/// See the [Rust documentation for `icu_provider`](https://docs.rs/icu_provider/2.0.0/icu_provider/index.html) for more information.
final class DataProvider implements ffi.Finalizable {
  final ffi.Pointer<ffi.Opaque> _ffi;

  // These are "used" in the sense that they keep dependencies alive
  // ignore: unused_field
  final core.List<Object> _selfEdge;

  // This takes in a list of lifetime edges (including for &self borrows)
  // corresponding to data this may borrow from. These should be flat arrays containing
  // references to objects, and this object will hold on to them to keep them alive and
  // maintain borrow validity.
  DataProvider._fromFfi(this._ffi, this._selfEdge) {
    if (_selfEdge.isEmpty) {
      _finalizer.attach(this, _ffi.cast());
    }
  }

  @_DiplomatFfiUse('icu4x_DataProvider_destroy_mv1')
  static final _finalizer = ffi.NativeFinalizer(ffi.Native.addressOf(_icu4x_DataProvider_destroy_mv1));

  /// See the [Rust documentation for `try_new_from_blob`](https://docs.rs/icu_provider_blob/2.0.0/icu_provider_blob/struct.BlobDataProvider.html#method.try_new_from_blob) for more information.
  ///
  /// Throws [DataError] on failure.
  factory DataProvider.fromByteSlice(ByteBuffer blob) {
    final result = _icu4x_DataProvider_from_owned_byte_slice_mv1(blob.asUint8List()._uint8AllocIn(_RustAlloc()));
    if (!result.isOk) {
      throw DataError.values[result.union.err];
    }
    return DataProvider._fromFfi(result.union.ok, []);
  }

  /// Creates a provider that tries the current provider and then, if the current provider
  /// doesn't support the data key, another provider `other`.
  ///
  /// This takes ownership of the `other` provider, leaving an empty provider in its place.
  ///
  /// See the [Rust documentation for `ForkByMarkerProvider`](https://docs.rs/icu_provider_adapters/2.0.0/icu_provider_adapters/fork/type.ForkByMarkerProvider.html) for more information.
  ///
  /// Throws [DataError] on failure.
  void forkByMarker(DataProvider other) {
    final result = _icu4x_DataProvider_fork_by_marker_mv1(_ffi, other._ffi);
    if (!result.isOk) {
      throw DataError.values[result.union.err];
    }
  }

  /// Same as `fork_by_key` but forks by locale instead of key.
  ///
  /// See the [Rust documentation for `IdentifierNotFoundPredicate`](https://docs.rs/icu_provider_adapters/2.0.0/icu_provider_adapters/fork/predicates/struct.IdentifierNotFoundPredicate.html) for more information.
  ///
  /// Throws [DataError] on failure.
  void forkByLocale(DataProvider other) {
    final result = _icu4x_DataProvider_fork_by_locale_mv1(_ffi, other._ffi);
    if (!result.isOk) {
      throw DataError.values[result.union.err];
    }
  }

  /// See the [Rust documentation for `new`](https://docs.rs/icu_provider_adapters/2.0.0/icu_provider_adapters/fallback/struct.LocaleFallbackProvider.html#method.new) for more information.
  ///
  /// Additional information: [1](https://docs.rs/icu_provider_adapters/2.0.0/icu_provider_adapters/fallback/struct.LocaleFallbackProvider.html)
  ///
  /// Throws [DataError] on failure.
  void enableLocaleFallbackWith(LocaleFallbacker fallbacker) {
    final result = _icu4x_DataProvider_enable_locale_fallback_with_mv1(_ffi, fallbacker._ffi);
    if (!result.isOk) {
      throw DataError.values[result.union.err];
    }
  }

}

@_DiplomatFfiUse('icu4x_DataProvider_destroy_mv1')
@ffi.Native<ffi.Void Function(ffi.Pointer<ffi.Void>)>(isLeaf: true, symbol: 'icu4x_DataProvider_destroy_mv1')
// ignore: non_constant_identifier_names
external void _icu4x_DataProvider_destroy_mv1(ffi.Pointer<ffi.Void> self);

@_DiplomatFfiUse('icu4x_DataProvider_from_owned_byte_slice_mv1')
@ffi.Native<_ResultOpaqueInt32 Function(_SliceUint8)>(isLeaf: true, symbol: 'icu4x_DataProvider_from_owned_byte_slice_mv1')
// ignore: non_constant_identifier_names
external _ResultOpaqueInt32 _icu4x_DataProvider_from_owned_byte_slice_mv1(_SliceUint8 blob);

@_DiplomatFfiUse('icu4x_DataProvider_fork_by_marker_mv1')
@ffi.Native<_ResultVoidInt32 Function(ffi.Pointer<ffi.Opaque>, ffi.Pointer<ffi.Opaque>)>(isLeaf: true, symbol: 'icu4x_DataProvider_fork_by_marker_mv1')
// ignore: non_constant_identifier_names
external _ResultVoidInt32 _icu4x_DataProvider_fork_by_marker_mv1(ffi.Pointer<ffi.Opaque> self, ffi.Pointer<ffi.Opaque> other);

@_DiplomatFfiUse('icu4x_DataProvider_fork_by_locale_mv1')
@ffi.Native<_ResultVoidInt32 Function(ffi.Pointer<ffi.Opaque>, ffi.Pointer<ffi.Opaque>)>(isLeaf: true, symbol: 'icu4x_DataProvider_fork_by_locale_mv1')
// ignore: non_constant_identifier_names
external _ResultVoidInt32 _icu4x_DataProvider_fork_by_locale_mv1(ffi.Pointer<ffi.Opaque> self, ffi.Pointer<ffi.Opaque> other);

@_DiplomatFfiUse('icu4x_DataProvider_enable_locale_fallback_with_mv1')
@ffi.Native<_ResultVoidInt32 Function(ffi.Pointer<ffi.Opaque>, ffi.Pointer<ffi.Opaque>)>(isLeaf: true, symbol: 'icu4x_DataProvider_enable_locale_fallback_with_mv1')
// ignore: non_constant_identifier_names
external _ResultVoidInt32 _icu4x_DataProvider_enable_locale_fallback_with_mv1(ffi.Pointer<ffi.Opaque> self, ffi.Pointer<ffi.Opaque> fallbacker);

// dart format on
