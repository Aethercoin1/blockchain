Shared Libraries
================

## aethercoinconsensus

The purpose of this library is to make the verification functionality that is critical to aethercoin's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `aethercoinconsensus.h` located in  `src/script/aethercoinconsensus.h`.

#### Version

`aethercoinconsensus_version` returns an `unsigned int` with the API version *(currently at an experimental `0`)*.

#### Script Validation

`aethercoinconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `aethercoinconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `aethercoinconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `aethercoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/aethercoin/bips/blob/master/bip-0016.mediawiki)) subscripts
- `aethercoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/aethercoin/bips/blob/master/bip-0066.mediawiki)) compliance

##### Errors
- `aethercoinconsensus_ERR_OK` - No errors with input parameters *(see the return value of `aethercoinconsensus_verify_script` for the verification status)*
- `aethercoinconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `aethercoinconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `aethercoinconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`

### Example Implementations
- [Naethercoin](https://github.com/NicolasDorier/Naethercoin/blob/master/Naethercoin/Script.cs#L814) (.NET Bindings)
- [node-libaethercoinconsensus](https://github.com/bitpay/node-libaethercoinconsensus) (Node.js Bindings)
- [java-libaethercoinconsensus](https://github.com/dexX7/java-libaethercoinconsensus) (Java Bindings)
- [aethercoinconsensus-php](https://github.com/Bit-Wasp/aethercoinconsensus-php) (PHP Bindings)
