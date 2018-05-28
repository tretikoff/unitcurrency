cmake_minimum_required(VERSION 3.10)
project(src)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
#include_directories(json)
#include_directories(obj)
#include_directories(qt)
#include_directories(qt/test)

add_executable(src
#        json/json_spirit.h
#        json/json_spirit_error_position.h
#        json/json_spirit_reader.cpp
#        json/json_spirit_reader.h
#        json/json_spirit_reader_template.h
#        json/json_spirit_stream_reader.h
#        json/json_spirit_utils.h
#        json/json_spirit_value.cpp
#        json/json_spirit_value.h
#        json/json_spirit_writer.cpp
#        json/json_spirit_writer.h
#        json/json_spirit_writer_template.h
#        obj/build.h
#        qt/test/test_main.cpp
#        qt/test/uritests.cpp
#        qt/test/uritests.h
#        qt/aboutdialog.cpp
#        qt/aboutdialog.h
#        qt/addressbookpage.cpp
#        qt/addressbookpage.h
#        qt/addresstablemodel.cpp
#        qt/addresstablemodel.h
#        qt/askpassphrasedialog.cpp
#        qt/askpassphrasedialog.h
#        qt/bitcoin.cpp
#        qt/bitcoinaddressvalidator.cpp
#        qt/bitcoinaddressvalidator.h
#        qt/bitcoinamountfield.cpp
#        qt/bitcoinamountfield.h
#        qt/bitcoingui.cpp
#        qt/bitcoingui.h
#        qt/bitcoinstrings.cpp
#        qt/bitcoinunits.cpp
#        qt/bitcoinunits.h
#        qt/clientmodel.cpp
#        qt/clientmodel.h
#        qt/csvmodelwriter.cpp
#        qt/csvmodelwriter.h
#        qt/editaddressdialog.cpp
#        qt/editaddressdialog.h
#        qt/guiconstants.h
#        qt/guiutil.cpp
#        qt/guiutil.h
#        qt/macdockiconhandler.h
#        qt/macdockiconhandler.mm
#        qt/miningpage.cpp
#        qt/miningpage.h
#        qt/monitoreddatamapper.cpp
#        qt/monitoreddatamapper.h
#        qt/notificator.cpp
#        qt/notificator.h
#        qt/optionsdialog.cpp
#        qt/optionsdialog.h
#        qt/optionsmodel.cpp
#        qt/optionsmodel.h
#        qt/overviewpage.cpp
#        qt/overviewpage.h
#        qt/qrcodedialog.cpp
#        qt/qrcodedialog.h
#        qt/qtipcserver.cpp
#        qt/qtipcserver.h
#        qt/qvalidatedlineedit.cpp
#        qt/qvalidatedlineedit.h
#        qt/qvaluecombobox.cpp
#        qt/qvaluecombobox.h
#        qt/rpcconsole.cpp
#        qt/rpcconsole.h
#        qt/sendcoinsdialog.cpp
#        qt/sendcoinsdialog.h
#        qt/sendcoinsentry.cpp
#        qt/sendcoinsentry.h
#        qt/signverifymessagedialog.cpp
#        qt/signverifymessagedialog.h
#        qt/transactiondesc.cpp
#        qt/transactiondesc.h
#        qt/transactiondescdialog.cpp
#        qt/transactiondescdialog.h
#        qt/transactionfilterproxy.cpp
#        qt/transactionfilterproxy.h
#        qt/transactionrecord.cpp
#        qt/transactionrecord.h
#        qt/transactiontablemodel.cpp
#        qt/transactiontablemodel.h
#        qt/transactionview.cpp
#        qt/transactionview.h
#        qt/walletmodel.cpp
#        qt/walletmodel.h
#        test/base32_tests.cpp
#        test/base58_tests.cpp
#        test/base64_tests.cpp
#        test/bignum_tests.cpp
#        test/Checkpoints_tests.cpp
#        test/DoS_tests.cpp
#        test/getarg_tests.cpp
#        test/key_tests.cpp
#        test/miner_tests.cpp
#        test/mruset_tests.cpp
#        test/multisig_tests.cpp
#        test/netbase_tests.cpp
#        test/rpc_tests.cpp
#        test/script_P2SH_tests.cpp
#        test/script_tests.cpp
#        test/sigopcount_tests.cpp
#        test/test_bitcoin.cpp
#        test/transaction_tests.cpp
#        test/uint160_tests.cpp
#        test/uint256_tests.cpp
#        test/util_tests.cpp
#        test/wallet_tests.cpp
        addrman.cpp
        addrman.h
        allocators.h
        base58.h
        bignum.h
        bitcoinrpc.cpp
        bitcoinrpc.h
        checkpoints.cpp
        checkpoints.h
        compat.h
        crypter.cpp
        crypter.h
        db.cpp
        db.h
        init.cpp
        init.h
        irc.cpp
        irc.h
        key.cpp
        key.h
        keystore.cpp
        keystore.h
        main.cpp
        main.h
        mruset.h
        net.cpp
        net.h
        netbase.cpp
        netbase.h
        noui.cpp
        protocol.cpp
        protocol.h
        rpcdump.cpp
        rpcnet.cpp
        rpcrawtransaction.cpp
        script.cpp
        script.h
        scrypt.c
        scrypt.h
        serialize.h
        strlcpy.h
        sync.cpp
        sync.h
        ui_interface.h
        uint256.h
        util.cpp
        util.h
        version.cpp
        version.h
        wallet.cpp
        wallet.h
        walletdb.cpp
        walletdb.h)
