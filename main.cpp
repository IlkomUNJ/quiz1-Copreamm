#include <iostream>
#include <limits>

#include "bank_customer.h"
#include "buyer.h"
#include "seller.h"

using namespace std;

enum PrimaryPrompt{LOGIN, REGISTER, EXIT};

enum RegisterPrompt{CREATE_BUYER, CREATE_SELLER, BACK};

enum LoginPrompt{
    CHECK_ACCOUNT, UPGRADE_SELLER, BANK_ACCOUNT_MENU, BROWSE_STORE, ORDER_FUNCTIONALITY, PAYMENT_FUNCTIONALITY, LOGOUT,
    // Opsi Seller, ditampilkan saat user adalah seller.
    CHECK_INVENTORY, ADD_ITEM, REMOVE_ITEM, VIEW_ORDERS
};

enum BankingPrompt{
    BALANCE_CHECK, TRANSACTION_HISTORY, DEPOSIT, WITHDRAW, BACK_BANKING
};


void handleSellerUpgrade() {
    cout << "\nUpgrade Account to Seller" << endl;
    cout << "Harus Memiliki Bank Account Sebelum Menjadi Seller" << endl;
    cout << "Masukkan detail Seller Anda (Nama Toko, Alamat, dll):" << endl;
    // Logika pembuatan/upgrade Seller akan berada di sini (memanggil constructor Seller)
    cout << "Upgrade ke Seller berhasil." << endl;
}

void handleBankingFunctions() {
    BankingPrompt bankingPrompt;
    int choice;
    do {
        cout << "Banking Account Functions" << endl;
        cout << "Select an option: " << endl;
        cout << "1. Balance Checking" << endl;
        cout << "2. Transaction History" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Select an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        bankingPrompt = static_cast<BankingPrompt>(choice - 1);

        switch (bankingPrompt) {
            case BALANCE_CHECK:
                cout << "Balance Checking selected." << endl;
                break;
            case TRANSACTION_HISTORY:
                cout << "Transaction History selected." << endl;
                break;
            case DEPOSIT:
                cout << "Deposit selected." << endl;
                break;
            case WITHDRAW:
                cout << "Withdraw selected." << endl;
                break;
            case BACK_BANKING:
                cout << "Returning to Main Menu..." << endl;
                return; // Exit the function to return to main menu
            default:
                cout << "Invalid option." << endl;
                break;
        }
    } while (bankingPrompt != BACK_BANKING);
}

void handleLoginMenu() {
    //User sudah login sebagai buyer atau seller
    //Perlu class Buyer dan Seller

    LoginPrompt loginPrompt;
    int choice;
    bool isSeller = false; //Ganti sesuai user

    do {
        cout << "Main Menu For Buyer" << endl;
        cout << "1. Check Account Status" << endl;
        cout << "2. Upgrade Account to Seller" << endl;

        //Asumsikan banking acc sudah ada, langsung ke banking fungsi
        cout << "3. Banking Account Functions" << endl;
        cout << "4. Browse Store" << endl;
        cout << "5. Order Functionality" << endl;
        cout << "6. Payment Functionality" << endl;
        cout << "7. Logout" << endl;

        if (isSeller) {
            cout << "More Menu For Seller" << endl;
            cout << "8. Check Inventory" << endl;
            cout << "9. Add Item to Inventory" << endl;
            cout << "10. Remove Item from Inventory" << endl;
            cout << "11. View Orders" << endl;
        }

        cout << "Select an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (!isSeller && choice > 7) {
            cout << "Invalid option. You are not registered as a Seller." << endl;
            continue;
        }

        loginPrompt = static_cast<LoginPrompt>(choice - 1);

        switch (loginPrompt){
            case CHECK_ACCOUNT:
            cout << "Check Account Status selected." << endl;
            //Tampilkan status buyer/seller dan banking account
            break;
            //Logika Untuk Buyer
            case UPGRADE_SELLER:
                handleSellerUpgrade();
                break;
            case BANK_ACCOUNT_MENU:
                handleBankingFunctions();
                break;
            case BROWSE_STORE:
                cout << "Browse Store selected." << endl;
                break;
            case ORDER_FUNCTIONALITY:
                cout << "Order Functionality selected." << endl;
                break;
            case PAYMENT_FUNCTIONALITY:
                cout << "Payment Functionality selected." << endl;  
                break;
            case LOGOUT:
                cout << "Logging out..." << endl;
                break;
            
            //Logika Untuk Seller
            case CHECK_INVENTORY:
                cout << "Check Inventory selected." << endl;
                break;
            case ADD_ITEM:
                cout << "Add Item to Inventory selected." << endl;
                break;
            case REMOVE_ITEM:
                cout << "Remove Item from Inventory selected." << endl;
                break;
            case VIEW_ORDERS:
                cout << "View Orders selected." << endl;
                break;
            
            default:
            cout << "Invalid option." << endl;
            break;
        }
    } while(true);
}

int main() {
    //create a loop prompt 
    PrimaryPrompt prompt = LOGIN;
    while (prompt != EXIT) {
        cout << "Main Menu" << endl;
        cout << "Select an option: " << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Your Option: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        prompt = static_cast<PrimaryPrompt>(choice - 1);

        switch (prompt) {
            case LOGIN:
                cout << "Login selected." << endl;
                handleLoginMenu();
                break;

            case REGISTER: {
                cout << "Register selected. " << endl;

                int regChoice;
                RegisterPrompt regPrompt = BACK;

                do {
                    cout << "Select an Option: " << endl;
                    cout << "1. Create Buyer Account" << endl;
                    cout << "2. Create Seller Account (Need Buyer Account and Banking)" << endl;
                    cout << "3. Back" << endl;
                    cout << "Your Option: ";
                    cin >> regChoice;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                        cout << "Invalid input. Please enter a number." << endl;
                        continue;
                    }

                    regPrompt = static_cast<RegisterPrompt>(regChoice - 1);

                    switch (regPrompt) {
                        case CREATE_BUYER:
                            cout << "Create Buyer Account selected." << endl;
                            break;
                        case CREATE_SELLER:
                            cout << "Create Seller Account selected." << endl;
                            break;
                        case BACK:
                            cout << "Back selected." << endl;
                            break;
                        default:
                            cout << "Invalid option." << endl;
                            break;
                    }
                } while (regPrompt != BACK);
                
                break;
            }

            case EXIT:
                cout << "Exiting." << std::endl;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
        cout << endl;
    }
    return 0;
}

/* if Login is selected, based on authority then provide options:
                assume user is logged in as Buyer for now
                1. Chek Account Status (will display if user is Buyer or Seller or both and linked banking account status)
                Will display Buyer, Seller and Banking Account details
                2. Upgrade Account to Seller
                Will prompt user to enter Seller details and create a Seller account linked to Buyer account
                Will reject if a user dont have a banking account linked
                3. Create Banking Account (if not already linked), will be replaced with banking functions
                Must provides: initial deposit amount, Address, Phone number, Email
                Banking functions will provides: Balance checking, Transaction History, Deposit, Withdraw (must)
                4. Browse Store Functionality
                Will display all stores initially
                Need to select a store to browse each store inventory
                Will display all items in the store inventory
                After selecting an item, will display item details and option to add to cart
                After adding to cart, will notify user item is added to cart
                5. Order Functionality
                Will display all items in cart
                Will provide option to remove item from cart
                Will provide option to checkout
                After checkout invoide will be generated (will go to payment functionality)
                6. Payment Functionality
                Will display all listed invoices
                Pick an invoice to pay
                Will display invoice details and total amount
                Will provide option to pay invoice
                Payment is done through confirmation dialogue
                In confirmation dialogue, will display account balance as precursor
                User will need to manually enter invoice id to pay
                After paying balance will be redacted from buyer and added to the responding seller account
                After payment, order status will be changed to paid
                7. Logout (return to main menu)
                Display confirmation dialogue
                If confirmed, return to main menu
                If not, return to Buyer menu
                
                Display confirmation dialogue
                If confirmed, delete account and return to main menu
                If not, return to Buyer menu
                assume user is logged in as Seller for now
                9. Check Inventory
                10. Add Item to Inventory
                11. Remove Item from Inventory
                12. View Orders (will display all orders placed to this seller
                Only orders with paid status will be listed
                Order details will listing items, quantity, total amount, buyer details, order status (paid, cancelled, completed)
                extra functions
                9. Exit to main Menu
                10. Exit Program
                **/

 /* if register is selected then went through registration process:
                1. Create a new Buyer Account
                Must provides: Name, Home Address, Phone number, Email
                2. Option to create a Seller Account (will be linked to Buyer account)
                Must provides 1: Store Name, Store Address, Store Phone number, Store Email
                Must provides 2: Home Address, Phone number, Email
                Must Provides 3: initial deposit amount.
                After finished immediately logged in as Buyer/Seller
                */

//BankCustomer customer1(1, "Alice", 1000.0);
//Buyer buyer1(1, customer1.getName(), customer1);