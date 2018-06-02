// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef AETHERCOIN_QT_AETHERCOINADDRESSVALIDATOR_H
#define AETHERCOIN_QT_AETHERCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class AetherCoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit AetherCoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** AetherCoin address widget validator, checks for a valid aethercoin address.
 */
class AetherCoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit AetherCoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // AETHERCOIN_QT_AETHERCOINADDRESSVALIDATOR_H
