# Changelog

## [1.45.120](https://github.com/brave/brave-browser/releases/tag/v1.45.120)

 - Fixed crash when viewing a retention notification in certain cases. ([#26444](https://github.com/brave/brave-browser/issues/26444))
 - Fixed crash when using the built-in password manager in certain cases. ([#26396](https://github.com/brave/brave-browser/issues/26396))
 - Fixed crash when viewing "In-app notification settings" under "App notification". ([#26440](https://github.com/brave/brave-browser/issues/26440))

## [1.45.116](https://github.com/brave/brave-browser/releases/tag/v1.45.116)

 - Upgraded Chromium to 107.0.5304.91. ([#26292](https://github.com/brave/brave-browser/issues/26292)) ([Changelog for 107.0.5304.91](https://chromium.googlesource.com/chromium/src/+log/107.0.5304.62..107.0.5304.91?pretty=fuller&n=1000))

## [1.45.113](https://github.com/brave/brave-browser/releases/tag/v1.45.113)

 - Added dialog for blocking cookie consent banners. ([#8974](https://github.com/brave/brave-browser/issues/8974))
 - Added QR code scanner to address bar. ([#21478](https://github.com/brave/brave-browser/issues/21478))
 - Added additional language pairs to Brave Translate. ([#24303](https://github.com/brave/brave-browser/issues/24303))
 - Added support for province level targeting for select Canadian provinces when using Brave Ads. ([#16682](https://github.com/brave/brave-browser/issues/16682))
 - [Security] Added additional password protection for Brave Wallet show private key. ([#24830](https://github.com/brave/brave-browser/issues/24830))
 - Implemented Solana connection state indicator on Brave Wallet panel. ([#24810](https://github.com/brave/brave-browser/issues/24810))
 - Implemented multi-chain pending transaction requests on Brave Wallet panel. ([#24928](https://github.com/brave/brave-browser/issues/24928))
 - Enabled theme support for Speedreader. ([#25116](https://github.com/brave/brave-browser/issues/25116))
 - Improved fingerprinting privacy by adding farbling protections for screen resolution and coordinates. ([#23170](https://github.com/brave/brave-browser/issues/23170))
 - Improved privacy by preventing private windows from inheriting permissions set in normal windows. ([#24720](https://github.com/brave/brave-browser/issues/24720))
 - Improved brave://rewards responsiveness. ([#24570](https://github.com/brave/brave-browser/issues/24570))
 - Updated the text colour of pre-set values to be more legible on the Brave Wallet "Send" screen. ([#24522](https://github.com/brave/brave-browser/issues/24522))
 - Updated verified vs. unverified criteria for Brave Rewards creator channels. ([#25085](https://github.com/brave/brave-browser/issues/25085))
 - Removed known Blueshift email tracking parameters from URLs. ([#25238](https://github.com/brave/brave-browser/issues/25238))
 - Fixed crash when switching/selecting networks and quickly viewing asset details via Brave Wallet. ([#25131](https://github.com/brave/brave-browser/issues/25131))
 - Fixed misaligned autocomplete icons under the address bar. ([#26063](https://github.com/brave/brave-browser/issues/26063))
 - Fixed misaligned on-touch animation under Top Sites. ([#24676](https://github.com/brave/brave-browser/issues/24676))
 - Upgraded Chromium to 107.0.5304.62. ([#26151](https://github.com/brave/brave-browser/issues/26151)) ([Changelog for 107.0.5304.62](https://chromium.googlesource.com/chromium/src/+log/106.0.5249.119..107.0.5304.62?pretty=fuller&n=1000))

## [1.44.114](https://github.com/brave/brave-browser/releases/tag/v1.44.114)

 - Fixed crash when tapping on Brave ads within the Brave News feed via the New Tab Page. ([#25933](https://github.com/brave/brave-browser/issues/25933))
 - Upgraded Chromium to 106.0.5249.126. ([#26018](https://github.com/brave/brave-browser/issues/26018)) ([Changelog for 106.0.5249.126](https://chromium.googlesource.com/chromium/src/+log/106.0.5249.119..106.0.5249.126?pretty=fuller&n=1000))

## [1.44.112](https://github.com/brave/brave-browser/releases/tag/v1.44.112)

 - Removed deprecated Ethereum Testnet's (Ropsten/Rinkeby/Kovan) and added support for Sepolia Testnet for Brave Wallet. ([#25654](https://github.com/brave/brave-browser/issues/25654))
 - Upgraded Chromium to 106.0.5249.119. ([#25926](https://github.com/brave/brave-browser/issues/25926)) ([Changelog for 106.0.5249.119](https://chromium.googlesource.com/chromium/src/+log/106.0.5249.103..106.0.5249.119?pretty=fuller&n=1000))

## [1.44.105](https://github.com/brave/brave-browser/releases/tag/v1.44.105)

 - Upgraded Chromium to 106.0.5249.91. ([#25737](https://github.com/brave/brave-browser/issues/25737)) ([Changelog for 106.0.5249.91](https://chromium.googlesource.com/chromium/src/+log/106.0.5249.65..106.0.5249.91?pretty=fuller&n=1000))

## [1.44.101](https://github.com/brave/brave-browser/releases/tag/v1.44.101)

 - Added .zil TLD support for Unstoppable Domains. ([#24621](https://github.com/brave/brave-browser/issues/24621))
 - Added "Prevent fingerprinting via language settings" under the "Brave Shields & privacy" settings. ([#24621](https://github.com/brave/brave-browser/issues/23919))  
 - Added Solana account creation dialog in Brave Wallet under the "Send" screen if Solana account doesn't exist. ([#24463](https://github.com/brave/brave-browser/issues/24463))  
 - Updated Brave Wallet to create a Solana account by default when creating or restoring a wallet and set Solana as the default network. ([#25432](https://github.com/brave/brave-browser/issues/25432))
 - Improved de-AMP functionality. ([#22917](https://github.com/brave/brave-browser/issues/22917))
 - Removed extra whitespace being added when pasting a contract address while adding a custom token in Brave Wallet. ([#24728](https://github.com/brave/brave-browser/issues/24728))
 - Removed support for legacy Brave Rewards anonymous Uphold cards. ([#24464](https://github.com/brave/brave-browser/issues/24464))
 - Removed 2 BAT minimum threshold under Brave Rewards before being able to use Uphold as a custodial provider. ([#24759](https://github.com/brave/brave-browser/issues/24759))
 - Fixed pending Solana Devnet requests not being displayed under "Transactions" via Brave Wallet. ([#24410](https://github.com/brave/brave-browser/issues/24410))
 - Fixed "Reset Brave Rewards" not working correctly when the Brave Rewards page is opened. ([#8776](https://github.com/brave/brave-browser/issues/8776))
 - Fixed Brave Rewards panel not displaying "Logged out" when wallet has been disconnected from custodian. ([#23480](https://github.com/brave/brave-browser/issues/23480))
 - Fixed Brave News feed not being displayed under active NTP when enabling through settings. ([#25500](https://github.com/brave/brave-browser/issues/25500))
 - Upgraded Chromium to 106.0.5249.65. ([#25629](https://github.com/brave/brave-browser/issues/25629)) ([Changelog for 106.0.5249.65](https://chromium.googlesource.com/chromium/src/+log/105.0.5195.127..106.0.5249.65?pretty=fuller&n=1000))

## [1.43.94](https://github.com/brave/brave-browser/releases/tag/v1.43.94)

 - Upgraded Chromium to 105.0.5195.136. ([#25431](https://github.com/brave/brave-browser/issues/25431)) ([Changelog for 105.0.5195.136](https://chromium.googlesource.com/chromium/src/+log/105.0.5195.127..105.0.5195.136?pretty=fuller&n=1000))

## [1.43.93](https://github.com/brave/brave-browser/releases/tag/v1.43.93)

 - Added "Bridge to Aurora" button under the "Asset" panel in Brave Wallet. ([#24446](https://github.com/brave/brave-browser/issues/24446))
 - Restored gesture requirement for async clipboard write access. ([#16890](https://github.com/brave/brave-browser/issues/16890))
 - Fixed crash when reaching the end of Brave News feed. ([#25312](https://github.com/brave/brave-browser/issues/25312))
 - Fixed button text not visible while using dark mode. ([#25225](https://github.com/brave/brave-browser/issues/25225))
 - Upgraded Chromium to 105.0.5195.127. ([#25377](https://github.com/brave/brave-browser/issues/25377)) ([Changelog for 105.0.5195.127](https://chromium.googlesource.com/chromium/src/+log/105.0.5195.102..105.0.5195.127?pretty=fuller&n=1000))

## [1.43.90](https://github.com/brave/brave-browser/releases/tag/v1.43.90)

 - Fixed crash when disabling Brave Ads under brave://rewards. ([#25191](https://github.com/brave/brave-browser/issues/25191))
 - Upgraded Chromium to 105.0.5195.102. ([#25173](https://github.com/brave/brave-browser/issues/25173)) ([Changelog for 105.0.5195.102](https://chromium.googlesource.com/chromium/src/+log/105.0.5195.68..105.0.5195.102?pretty=fuller&n=1000))

## [1.43.88](https://github.com/brave/brave-browser/releases/tag/v1.43.88)

 - Added Brave Translate. ([#23770](https://github.com/brave/brave-browser/issues/23770))
 - Added dynamic Brave Ads payout status UI to Brave Rewards. ([#23429](https://github.com/brave/brave-browser/issues/23429))
 - [Security] Implemented feature policy for Ethereum and Solana for iframes. ([#23710](https://github.com/brave/brave-browser/issues/23710))
 - Updated several onboarding strings to improve the experience for users in India locales. ([#24111](https://github.com/brave/brave-browser/issues/24111))
 - Updated IPFS to use a longer delay between reconnection attempts. ([#24461](https://github.com/brave/brave-browser/issues/24461))
 - Fixed native token not being used when switching networks under both the "Send" and "Swap" panels in Brave Wallet. ([#22572](https://github.com/brave/brave-browser/issues/22572))
 - Fixed native token not being updated when network is changed under the "DApp" panel in Brave Wallet. ([#24078](https://github.com/brave/brave-browser/issues/24078))
 - Fixed incorrect image being used for the pending contribution message in Brave Rewards. ([#24006](https://github.com/brave/brave-browser/issues/24006))
 - Fixed Brave News settings bar being cut off when scrolling through the news feed under the New Tab Page. ([#21737](https://github.com/brave/brave-browser/issues/21737))
 - Fixed Brave News display issue when scrolling through the news feed after changing orientation while under the New Tab Page. ([#22439](https://github.com/brave/brave-browser/issues/22439))
 - Fixed scrolling issue when swiping through the news feed under the New Tab Page for Brave News. ([#22434](https://github.com/brave/brave-browser/issues/22434))
 - Fixed inconsistency between the "Sync Chain Code" and "Sync Chain QR Code" error messages in Brave Sync. ([#23948](https://github.com/brave/brave-browser/issues/23948))
 - Fixed "Show simplified view" being displayed in certain cases even though the setting has been disabled via the "Accessibility" settings. ([#14749](https://github.com/brave/brave-browser/issues/14749))
 - Fixed string alignment issue under the "Help make Brave better" onboarding panel at first launch. ([#24003](https://github.com/brave/brave-browser/issues/24003))
 - Upgraded Chromium to 105.0.5195.68. ([#25009](https://github.com/brave/brave-browser/issues/25009)) ([Changelog for 105.0.5195.68](https://chromium.googlesource.com/chromium/src/+log/104.0.5112.102..105.0.5195.68?pretty=fuller&n=1000))

## [1.42.97](https://github.com/brave/brave-browser/releases/tag/v1.42.97)

 - Added Solana support for account creation, sending SOL and sending SPL tokens with Brave Wallet. ([#24133](https://github.com/brave/brave-browser/issues/24133))
 - Improved fingerprint farbling for subresources. ([#24282](https://github.com/brave/brave-browser/issues/24282))
 - Updated tokens list for Aurora Chain in Brave Wallet. ([#24473](https://github.com/brave/brave-browser/issues/24473))
 - Fixed balance not being updated correctly when changing networks via Brave Wallet. ([#24272](https://github.com/brave/brave-browser/issues/24272))
 - Upgraded Chromium to 104.0.5112.102. ([#24713](https://github.com/brave/brave-browser/issues/24713)) ([Changelog for 104.0.5112.102](https://chromium.googlesource.com/chromium/src/+log/104.0.5112.81..104.0.5112.102?pretty=fuller&n=1000))

## [1.42.94](https://github.com/brave/brave-browser/releases/tag/v1.42.94)

 - Added Aurora EVM chain to preloaded chains for Brave Wallet. ([#23522](https://github.com/brave/brave-browser/issues/23522))
 - Added the ability to debounce URLs based on a regex applied to the path. ([#23121](https://github.com/brave/brave-browser/issues/23121))
 - Added pending request notification to Brave Wallet icon badge for Decrypt screen. ([#23613](https://github.com/brave/brave-browser/issues/23613))
 - Improved Brave Wallet UI on various screens to show the gradient color when selected. ([#23556](https://github.com/brave/brave-browser/issues/23556))
 - Improved fingerprint farbling in aggressive mode. ([#24126](https://github.com/brave/brave-browser/issues/24126))
 - Updated default search engine to Brave Search for new installations in certain regions. ([#23814](https://github.com/brave/brave-browser/issues/23814))
 - Removed known Marketo email tracking parameters from URLs. ([#9018](https://github.com/brave/brave-browser/issues/9018))
 - Removed P3A protobuf reporting. ([#23147](https://github.com/brave/brave-browser/issues/23147))
 - Fixed incorrect token being set as default when selecting Buy/Send from token details page in Brave Wallet. ([#22574](https://github.com/brave/brave-browser/issues/22574))
 - Fixed cosmetic filters not being applied inside of child frames. ([#22781](https://github.com/brave/brave-browser/issues/22781))
 - Fixed input field from being blocked by auto-complete suggestions on certain sites. ([#23487](https://github.com/brave/brave-browser/issues/23487))
 - Fixed Brave Wallet account address to be displayed in the same line when selected. ([#23558](https://github.com/brave/brave-browser/issues/23558))
 - Fixed Brave Wallet icon color to match based on site theme color. ([#23632](https://github.com/brave/brave-browser/issues/23632))
 - Fixed Brave Wallet interaction notification when tab focus is changed. ([#23745](https://github.com/brave/brave-browser/issues/23745))
 - Fixed incorrect balance being shown for certain tokens in Brave Wallet. ([#23998](https://github.com/brave/brave-browser/issues/23998))
 - Upgraded Chromium to 104.0.5112.81. ([#24364](https://github.com/brave/brave-browser/issues/24364)) ([Changelog for 104.0.5112.81](https://chromium.googlesource.com/chromium/src/+log/103.0.5060.134..104.0.5112.81?pretty=fuller&n=1000))

## [1.41.100](https://github.com/brave/brave-browser/releases/tag/v1.41.100)

 - Fixed crash which occurred when searching on certain sites due to debouncing. ([#24164](https://github.com/brave/brave-browser/issues/24164))

## [1.41.99](https://github.com/brave/brave-browser/releases/tag/v1.41.99)

 - Fixed error page being shown when debouncing in certain cases. ([#24080](https://github.com/brave/brave-browser/issues/24080))
 - Upgraded Chromium to 103.0.5060.134. ([#24122](https://github.com/brave/brave-browser/issues/24122)) ([Changelog for 103.0.5060.134](https://chromium.googlesource.com/chromium/src/+log/103.0.5060.114..103.0.5060.134?pretty=fuller&n=1000))

## [1.41.96](https://github.com/brave/brave-browser/releases/tag/v1.41.96)

 - Implemented time-limited sync code words. ([#22242](https://github.com/brave/brave-browser/issues/22242))
 - Added host related information including the ability to disconnect from Brave VPN via the persistent notification. ([#21997](https://github.com/brave/brave-browser/issues/21997))
 - Added DApp decrypt request screen. ([#23260](https://github.com/brave/brave-browser/issues/23260))
 - Improved privacy by preventing pages from passing identifiers through "window.name". ([#5910](https://github.com/brave/brave-browser/issues/5910))
 - Updated the onboarding welcome screens. ([#22946](https://github.com/brave/brave-browser/issues/22946))
 - Updated the brand logo for Ecosia throughout Brave. ([#23405](https://github.com/brave/brave-browser/issues/23405))
 - Removed "Desktop Mode" from "Site Settings" as it's a duplicate of "Desktop site". ([#23652](https://github.com/brave/brave-browser/issues/23652))
 - Fixed not being able to send Non-Fungible Token (ERC721) tokens. ([#23508](https://github.com/brave/brave-browser/issues/23508))
 - Fixed Swap "To" token value from resetting to 0 when Swap "From" token is changed ([#23631](https://github.com/brave/brave-browser/issues/23631))
 - Fixed crash when adding Harmony network into Brave Wallet when the locale is set to Hindi. ([#23775](https://github.com/brave/brave-browser/issues/23775))
 - Fixed blogspot.com URLs not being debounced. ([#22894](https://github.com/brave/brave-browser/issues/22894))

## [1.40.113](https://github.com/brave/brave-browser/releases/tag/v1.40.113)

 - Upgraded Chromium to 103.0.5060.114. ([#23860](https://github.com/brave/brave-browser/issues/23860)) ([Changelog for 103.0.5060.114](https://chromium.googlesource.com/chromium/src/+log/103.0.5060.66..103.0.5060.114?pretty=fuller&n=1000))

## [1.40.111](https://github.com/brave/brave-browser/releases/tag/v1.40.111)

 - Upgraded Chromium to 103.0.5060.70. ([#23779](https://github.com/brave/brave-browser/issues/23779)) ([Changelog for 103.0.5060.70](https://chromium.googlesource.com/chromium/src/+log/103.0.5060.53..103.0.5060.70?pretty=fuller&n=1000))

## [1.40.106](https://github.com/brave/brave-browser/releases/tag/v1.40.106)

 - Fixed browser crash when app is brought into view from background with a pending action in Brave Wallet panel while notification badge is shown. ([#23604](https://github.com/brave/brave-browser/issues/23604))

## [1.40.105](https://github.com/brave/brave-browser/releases/tag/v1.40.105)

 - Added Dapps support for Brave Wallet. ([#23159](https://github.com/brave/brave-browser/issues/23159))
 - Added support to list Non-Fungible Token (ERC721) in Brave Wallet. ([#19565](https://github.com/brave/brave-browser/issues/19565))
 - Added pre-loaded EVMs into Brave Wallet network selector (supported by 0x). ([#22888](https://github.com/brave/brave-browser/issues/22888))
 - Added ability to remove "Top Tiles" from the New Tab Page via the "New Tab Page" settings. ([#23118](https://github.com/brave/brave-browser/issues/23118))
 - Retired the option of using DNS over HTTPS for Unstoppable Domains resolution now that layer 2 support has been added. ([#22149](https://github.com/brave/brave-browser/issues/22149))
 - Changed Ethereum Dapp provider to only be available in secure contexts. ([#23407](https://github.com/brave/brave-browser/issues/23407))
 - Changed Unstoppable Domains user opt-in interstitial from Cloudflare DoH to Ethereum option. ([#22148](https://github.com/brave/brave-browser/issues/22148))
 - Removed "Beta" from Brave Wallet via the settings menu. ([#23238](https://github.com/brave/brave-browser/issues/23238))
 - Updated QR sync code generator to include Brave icon when creating new QR sync codes. ([#22420](https://github.com/brave/brave-browser/issues/22420)) 
 - Fixed Ethereum Dapps dialog being opened in inactive tabs. ([#23460](https://github.com/brave/brave-browser/issues/23460))
 - Fixed selected network being used when resolving Unstoppable Domains/Ethereum Name Service to ETH address. ([#22151](https://github.com/brave/brave-browser/issues/22151))
 - Fixed crash when selecting "VPN Support" under the "Brave Firewall + VPN" settings in certain cases. ([#23492](https://github.com/brave/brave-browser/issues/23492))
 - Fixed not being able to copy sync code from existing sync chain in certain cases. ([#23206](https://github.com/brave/brave-browser/issues/23206))
 - Fixed issue where setting Brave as the default browser using the onboarding screen didn't work in certain cases. ([#22766](https://github.com/brave/brave-browser/issues/22766))
 - Upgraded Chromium to 103.0.5060.53. ([#23482](https://github.com/brave/brave-browser/issues/23482)) ([Changelog for 103.0.5060.53](https://chromium.googlesource.com/chromium/src/+log/102.0.5005.115..103.0.5060.53?pretty=fuller&n=1000))

## [1.39.123](https://github.com/brave/brave-browser/releases/tag/v1.39.123)

 - Fixed certain cases where AMP pages would get into a redirect loop. ([#23320](https://github.com/brave/brave-browser/issues/23320))
 - Upgraded Chromium to 102.0.5005.125. ([#23444](https://github.com/brave/brave-browser/issues/23444)) ([Changelog for 102.0.5005.125](https://chromium.googlesource.com/chromium/src/+log/102.0.5005.99..102.0.5005.125?pretty=fuller&n=1000))

## [1.39.120](https://github.com/brave/brave-browser/releases/tag/v1.39.120)

 - Changed position of VPN toggle under settings menu. ([#23240](https://github.com/brave/brave-browser/issues/23240))
 - Fixed browser crash when device attempts connecting to Google Play Store after losing network connectivity in certain cases. ([#23177](https://github.com/brave/brave-browser/issues/23177))
 - Fixed subscription status under Brave Firewall + VPN settings not specifying if it's a trial, monthly or yearly subscription. ([#23004](https://github.com/brave/brave-browser/issues/23004))
 - Fixed errors during sync decryption which caused Brave Sync to fail in certain cases. ([#22898](https://github.com/brave/brave-browser/issues/22898))
 - Fixed certain cases where AMP pages would go into loading loop. ([#22610](https://github.com/brave/brave-browser/issues/22610))
 - Upgraded Chromium to 102.0.5005.99. ([#23311](https://github.com/brave/brave-browser/issues/23311)) ([Changelog for 102.0.5005.99](https://chromium.googlesource.com/chromium/src/+log/102.0.5005.78..102.0.5005.99?pretty=fuller&n=1000))

## [1.39.115](https://github.com/brave/brave-browser/releases/tag/v1.39.115)

 - Disabled Brave Firewall + VPN on both Android 6 and Android 7 due to several crashes. ([#23063](https://github.com/brave/brave-browser/issues/23063)) & ([#23089](https://github.com/brave/brave-browser/issues/23089))
 - Fixed cookies being cleared/removed when upgrading from Chromium 101 to Chromium 102. ([#23109](https://github.com/brave/brave-browser/issues/23109))
 - Upgraded Chromium to 102.0.5005.78. ([#23131](https://github.com/brave/brave-browser/issues/23131)) ([Changelog for 102.0.5005.78](https://chromium.googlesource.com/chromium/src/+log/102.0.5005.61..102.0.5005.78?pretty=fuller&n=1000))

## [1.39.111](https://github.com/brave/brave-browser/releases/tag/v1.39.111)

 - Added Brave Firewall + VPN. ([#12197](https://github.com/brave/brave-browser/issues/12197))
 - Added support for blob partitioning. ([#21746](https://github.com/brave/brave-browser/issues/21746))
 - Implemented eth_getEncryptionPublicKey for Brave Wallet. ([#19276](https://github.com/brave/brave-browser/issues/19276))
 - Reduced adblock filter memory usage by optimizing unused regex rules. ([#21970](https://github.com/brave/brave-browser/issues/21970))
 - Removed known Dialog Insight user tracking parameters from URLs. ([#22082](https://github.com/brave/brave-browser/issues/22082))
 - Fixed breakage in webpack build caused by OpenSSL 3.0. ([#22305](https://github.com/brave/brave-browser/issues/22305))
 - Fixed pending bell icon under Brave Wallet not being displayed when new unapproved requests are created. ([#21654](https://github.com/brave/brave-browser/issues/21654))
 - Fixed expand icon under Brave Shields using incorrect color when the Privacy Hub has been enabled. ([#22049](https://github.com/brave/brave-browser/issues/22049))
 - Upgraded Chromium to 102.0.5005.61. ([#22923](https://github.com/brave/brave-browser/issues/22923)) ([Changelog for 102.0.5005.61](https://chromium.googlesource.com/chromium/src/+log/101.0.4951.67..102.0.5005.61?pretty=fuller&n=1000))

## [1.38.119](https://github.com/brave/brave-browser/releases/tag/v1.38.119)

 - Added Brave News opt-in card via the New Tab Page. ([#22778](https://github.com/brave/brave-browser/issues/22778))
 - Reimplemented the ability to override page elements with "!important" styles using cosmetic filtering. ([#22264](https://github.com/brave/brave-browser/issues/22264))
 - Refactored gas fee estimations to help increase successful transactions for Brave Wallet. ([#22640](https://github.com/brave/brave-browser/issues/22640))
 - Fixed Brave Wallet disambiguation between Thor on Avalanche vs Thorswap on Ethereum. ([#22651](https://github.com/brave/brave-browser/issues/22651))
 - Fixed selected custom networks not being displayed within the Brave Wallet portfolio page when selected via the dropdown menu. ([#22425](https://github.com/brave/brave-browser/issues/22425))
 - Fixed incorrect starting position being used when opening a new tab within another New Tab Page while Brave News is enabled. ([#22549](https://github.com/brave/brave-browser/issues/22549))
 - Fixed crash when changing device orientation and scrolling through the New Tab Page after upgrade in certain cases. ([#22777](https://github.com/brave/brave-browser/issues/22777))
 - Fixed Brave News feed reappearing via the New Tab Page after being disabled when changing the device orientation. ([#22444](https://github.com/brave/brave-browser/issues/22444))
 - Fixed Brave News position not being retained when switching between different tabs. ([#22356](https://github.com/brave/brave-browser/issues/22356))
 - Fixed tapping on "Load new content" takes user to the second card within the news feed rather than at the beginning of feed. ([#22183](https://github.com/brave/brave-browser/issues/22183))
 - Upgraded Chromium to 101.0.4951.67. ([#22896](https://github.com/brave/brave-browser/issues/22896)) ([Changelog for 101.0.4951.67](https://chromium.googlesource.com/chromium/src/+log/101.0.4951.61..101.0.4951.67?pretty=fuller&n=1000))

## [1.38.113](https://github.com/brave/brave-browser/releases/tag/v1.38.113)

 - Upgraded Chromium to 101.0.4951.61. ([#22760](https://github.com/brave/brave-browser/issues/22760)) ([Changelog for 101.0.4951.61](https://chromium.googlesource.com/chromium/src/+log/101.0.4951.41..101.0.4951.61?pretty=fuller&n=1000))

## [1.38.109](https://github.com/brave/brave-browser/releases/tag/v1.38.109)

 - Added Gemini two-way Brave Rewards wallet. ([#17408](https://github.com/brave/brave-browser/issues/17408))
 - Added the ability to redirect an AMP page to its canonical non-AMP version. ([#21643](https://github.com/brave/brave-browser/issues/21643))
 - Added the ability to customize the nonce for unapproved Brave Wallet transactions via the transactions confirmation screen. ([#21459](https://github.com/brave/brave-browser/issues/21459))
 - Added "Clear wallet transaction and nonce information" setting for Brave Wallet under "Settings". ([#21457](https://github.com/brave/brave-browser/issues/21457))
 - Added notification for Brave Wallet pending transactions. ([#19837](https://github.com/brave/brave-browser/issues/19837))
 - Added "Show all pending contributions" view into Brave Wallet. ([#17038](https://github.com/brave/brave-browser/issues/17038))
 - Updated the Brave Wallet network selector screen. ([#20471](https://github.com/brave/brave-browser/issues/20471))
 - Updated adblocking to execute all cosmetic scriptlets even if one fails. ([#21932](https://github.com/brave/brave-browser/issues/21932))
 - Renamed "Monthly Contributions" to "Monthly Tips" for Brave Rewards. ([#20564](https://github.com/brave/brave-browser/issues/20564))
 - Removed referral code from P3A reports. ([#21460](https://github.com/brave/brave-browser/issues/21460))
 - Fixed crash when opening the swap page under Brave Wallet for custom watchlist assets. ([#22164](https://github.com/brave/brave-browser/issues/22164))
 - Fixed users swap values automatically being changed due to the market price constantly being updated in Brave Wallet. ([#22308](https://github.com/brave/brave-browser/issues/22308))
 - Fixed both "Approve" and "Reject" buttons overlapping the details section when initiating swaps. ([#21605](https://github.com/brave/brave-browser/issues/21605))
 - Fixed "Approve/Reject" dialog not being displayed for unapproved Brave Wallet transactions via "Asset Details". ([#21458](https://github.com/brave/brave-browser/issues/21458))
 - Fixed switching networks in Brave Wallet via the "Send" screen not resetting input values. ([#21136](https://github.com/brave/brave-browser/issues/21136))
 - Fixed unblocked cookie consent dialogs on some websites when the brave://flags/#brave-adblock-cookie-list-default is enabled. ([#22032](https://github.com/brave/brave-browser/issues/22032))
 - Upgraded Chromium to 101.0.4951.41. ([#22431](https://github.com/brave/brave-browser/issues/22431)) ([Changelog for 101.0.4951.41](https://chromium.googlesource.com/chromium/src/+log/100.0.4896.127..101.0.4951.41?pretty=fuller&n=1000))

## [1.37.116](https://github.com/brave/brave-browser/releases/tag/v1.37.116)

 - Improved general performance by fixing cosmetic filters. ([#22030](https://github.com/brave/brave-browser/issues/22030))
 - Added "Enable Tab Group auto creation" setting under "Appearance" which controls the ability to open links in separate tabs. ([#22105](https://github.com/brave/brave-browser/issues/22105))
 - Fixed rounding issues under Brave Wallet via the "Send" and "Swap" panels by increasing the digits after the decimal to 0.00000000 (8 digits) from 0.000000 (6 digits). ([#22257](https://github.com/brave/brave-browser/issues/22257))
 - Fixed crash when attempting to send opened tab to another devices on sync chain using "Send to your devices". ([#22128](https://github.com/brave/brave-browser/issues/22128))
 - Upgraded Chromium to 100.0.4896.127. ([#22318](https://github.com/brave/brave-browser/issues/22318)) ([Changelog for 100.0.4896.127](https://chromium.googlesource.com/chromium/src/+log/100.0.4896.88..100.0.4896.127?pretty=fuller&n=1000))

## [1.37.113](https://github.com/brave/brave-browser/releases/tag/v1.37.113)

 - Upgraded Chromium to 100.0.4896.88. ([#22221](https://github.com/brave/brave-browser/issues/22221)) ([Changelog for 100.0.4896.88](https://chromium.googlesource.com/chromium/src/+log/100.0.4896.79..100.0.4896.88?pretty=fuller&n=1000))

## [1.37.112](https://github.com/brave/brave-browser/releases/tag/v1.37.112)

 - Fixed crash when enabling or disabling P3A in certain cases. ([#22037](https://github.com/brave/brave-browser/issues/22037))
 - Upgraded Chromium to 100.0.4896.79. ([#22077](https://github.com/brave/brave-browser/issues/22077)) ([Changelog for 100.0.4896.79](https://chromium.googlesource.com/chromium/src/+log/100.0.4896.60..100.0.4896.79?pretty=fuller&n=1000))

## [1.37.111](https://github.com/brave/brave-browser/releases/tag/v1.37.111)

 - Upgraded Chromium to 100.0.4896.79. ([#22077](https://github.com/brave/brave-browser/issues/22077)) ([Changelog for 100.0.4896.79](https://chromium.googlesource.com/chromium/src/+log/100.0.4896.60..100.0.4896.79?pretty=fuller&n=1000))

## [1.37.110](https://github.com/brave/brave-browser/releases/tag/v1.37.110)

 - Fixed crash when enabling or disabling P3A in certain cases. ([#22037](https://github.com/brave/brave-browser/issues/22037))

## [1.37.109](https://github.com/brave/brave-browser/releases/tag/v1.37.109)

 - Added fee oracle for EIP-1559 to estimate priority fees in Brave Wallet. ([#20469](https://github.com/brave/brave-browser/issues/20469))
 - Added ability to to override page elements with "!important" styles using cosmetic filtering. ([#20177](https://github.com/brave/brave-browser/issues/20177))
 - Improved selection of RPC URLs after input from chainlist.org with variables and wss:// (Affects Arbitrum). ([#20958](https://github.com/brave/brave-browser/issues/20958))
 - Improved adblocking by applying generic cosmetic filters from brave://adblock into "Standard" shields blocking mode. ([#20855](https://github.com/brave/brave-browser/issues/20855))
 - Removed references of "Brave DEX Aggregator" from Brave Wallet. ([#20463](https://github.com/brave/brave-browser/issues/20463))
 - Fixed transaction status not being updated in certain cases for pending transactions in Brave Wallet. ([#21300](https://github.com/brave/brave-browser/issues/21300))
 - Fixed biometric still enabled after Brave Wallet has been reset via brave://settings/wallet. ([#20444](https://github.com/brave/brave-browser/issues/20444))
 - Fixed new Brave Wallet transactions not being added into the "Buy", "Send" and "Swap" panels. ([#20677](https://github.com/brave/brave-browser/issues/20677))
 - Fixed switching to "Private" mode opened a "Standard" tab in certain cases. [#21877](https://github.com/brave/brave-browser/issues/21877))
 - Fixed desktop mode not working in certain cases. ([#20936](https://github.com/brave/brave-browser/issues/20936))
 - Fixed New Tab Page Sponsored Image text being cut off at the bottom on certain devices with smaller screen size. ([#21736](https://github.com/brave/brave-browser/issues/21736))
 - Upgraded Chromium to 100.0.4896.60. ([#21953](https://github.com/brave/brave-browser/issues/21953)) ([Changelog for 100.0.4896.60](https://chromium.googlesource.com/chromium/src/+log/99.0.4844.88..100.0.4896.60?pretty=fuller&n=1000))

## [1.36.122](https://github.com/brave/brave-browser/releases/tag/v1.36.122)

 - Upgraded Chromium to 99.0.4844.88. ([#21889](https://github.com/brave/brave-browser/issues/21889)) ([Changelog for 99.0.4844.88](https://chromium.googlesource.com/chromium/src/+log/99.0.4844.83..99.0.4844.88?pretty=fuller&n=1000))

## [1.36.116](https://github.com/brave/brave-browser/releases/tag/v1.36.116)

 - Fixed Brave News onboarding card still appearing under New Tab Page in certain cases when Brave News has already been enabled via settings. ([#21493](https://github.com/brave/brave-browser/issues/21493))
 - Upgraded Chromium to 99.0.4844.74. ([#21693](https://github.com/brave/brave-browser/issues/21693)) ([Changelog for 99.0.4844.74](https://chromium.googlesource.com/chromium/src/+log/99.0.4844.51..99.0.4844.74?pretty=fuller&n=1000))

## [1.36.112](https://github.com/brave/brave-browser/releases/tag/v1.36.112)

 - Fixed crash due to autocomplete in certain cases. ([#21558](https://github.com/brave/brave-browser/issues/21558))

## [1.36.111](https://github.com/brave/brave-browser/releases/tag/v1.36.111)

 - Added EVM support for compatible chains under Brave Wallet. ([#20337](https://github.com/brave/brave-browser/issues/20337))
 - Added ability to restore Brave Crypto wallets within Brave Wallet using legacy 24-word mnemonic. ([#18459](https://github.com/brave/brave-browser/issues/18459))
 - Added WebSockets connection pool limit when shields are enabled. ([#19990](https://github.com/brave/brave-browser/issues/19990))
 - Added ability to completely disable autocomplete under "Brave Shields and privacy" settings. ([#19647](https://github.com/brave/brave-browser/issues/19647))
 - Added EIP-55 checksum address checks in the send widget. ([#20132](https://github.com/brave/brave-browser/issues/20132))
 - Added ability to enable Brave News via settings. ([#21477](https://github.com/brave/brave-browser/issues/21477))
 - Added ability to scroll through websites within tab groups using swipe gestures. ([#19902](https://github.com/brave/brave-browser/issues/19902))
 - Updated P3A pings to use JSON format. ([#15967](https://github.com/brave/brave-browser/issues/15967))
 - Updated setting name and description for "Automatically send diagnostic reports" under brave://settings/privacy for clarity. ([#19822](https://github.com/brave/brave-browser/issues/19822))
 - Removed the tab stack layout in favor of tab overview mode. ([#21005](https://github.com/brave/brave-browser/issues/21005))
 - Fixed crash during onboarding when creating a Brave Wallet on certain devices that have biometric unlock enabled. ([#21153](https://github.com/brave/brave-browser/issues/21153))
 - Fixed biometric unlock only being displayed when initially launching Brave Wallet. ([#19973](https://github.com/brave/brave-browser/issues/19973))
 - Fixed biometric unlock not being displayed when auto-lock is triggered within Brave Wallet. ([#20036](https://github.com/brave/brave-browser/issues/20036))
 - Fixed custom network being removed when editing ChainID while custom network not set as default. ([#21046](https://github.com/brave/brave-browser/issues/21046))
 - Fixed selecting unapproved transactions not displaying the approval screen. ([#19969](https://github.com/brave/brave-browser/issues/19969))
 - Fixed both "Buy" and "Swap" screens not being closed when an unsupported network is selected. ([#20977](https://github.com/brave/brave-browser/issues/20977))
 - Fixed being able to select the same token under both the "From" and "To" fields when using Swaps via Brave Wallet. ([#20005](https://github.com/brave/brave-browser/issues/20005))
 - Fixed incorrect asset icons being used in certain cases for Brave Wallet. ([#20649](https://github.com/brave/brave-browser/issues/20649))
 - Fixed verify recovery phrase page being displayed when backup wallet is selected after resetting Brave Wallet. ([#20532](https://github.com/brave/brave-browser/issues/20532))
 - Fixed cursor being reset to beginning of recovery phrase when "Show recovery" is selected. ([#20465](https://github.com/brave/brave-browser/issues/20465))
 - Fixed several theme issues with Brave Wallet. ([#19827](https://github.com/brave/brave-browser/issues/19827))
 - Fixed both "Submit" and "Add" buttons being cutoff when adding custom networks via Brave Wallet. ([#20962](https://github.com/brave/brave-browser/issues/20962))
 - Upgraded Chromium to 99.0.4844.51. ([#21370](https://github.com/brave/brave-browser/issues/21370)) ([Changelog for 99.0.4844.51](https://chromium.googlesource.com/chromium/src/+log/98.0.4758.109..99.0.4844.51?pretty=fuller&n=1000))

## [1.35.103](https://github.com/brave/brave-browser/releases/tag/v1.35.103)

 - Added bitFlyer notification for Japan region only to let users know bitFlyer is available as a custodian. ([#20725](https://github.com/brave/brave-browser/issues/20725))
 - Fixed crash when attempting to send opened tab to another devices on sync chain using "Send to your devices". ([#21035](https://github.com/brave/brave-browser/issues/21035))
 - Upgraded Chromium to 98.0.4758.102. ([#21093](https://github.com/brave/brave-browser/issues/21093)) ([Changelog for 98.0.4758.102](https://chromium.googlesource.com/chromium/src/+log/98.0.4758.87..98.0.4758.102?pretty=fuller&n=1000))

## [1.35.101](https://github.com/brave/brave-browser/releases/tag/v1.35.101)

 - Fixed issues with "Desktop mode" which prevented users from being able to view websites in desktop mode. ([#20963](https://github.com/brave/brave-browser/issues/20963))
 - Fixed phone model being leaked via "navigator.userAgent". ([#20499](https://github.com/brave/brave-browser/issues/20499))
 - Fixed crash when adding large values into swap input field via Brave Wallet. ([#20881](https://github.com/brave/brave-browser/issues/20881))

## [1.35.100](https://github.com/brave/brave-browser/releases/tag/v1.35.100)

 - Added bitFlyer two-way Brave Rewards wallet for Japan region. ([#18439](https://github.com/brave/brave-browser/issues/18439))
 - Added "Brave" into the web search context menu when opening links in other browsers. ([#19842](https://github.com/brave/brave-browser/issues/19842))
 - Added notification for Uphold verified users when Customer Due Diligence survey needs to be completed. ([#20497](https://github.com/brave/brave-browser/issues/20497))
 - Added "wallet_requestPermissions" and "wallet_getPermissions" for compatibility with https://market.x.immutable.com and others. ([#19274](https://github.com/brave/brave-browser/issues/19274))
 - Added support for "wallet_watchAsset" method to add suggested tokens. ([#17878](https://github.com/brave/brave-browser/issues/17878))
 - Added EIP-55 checksum address checks in the send widget. ([#19532](https://github.com/brave/brave-browser/issues/19532))
 - Updated rewards panel design. ([#18471](https://github.com/brave/brave-browser/issues/18471))
 - Reduced BAT threshold before being able to verify Uphold two-way user wallet from 15 to 2 BAT. ([#19912](https://github.com/brave/brave-browser/issues/19912))
 - Removed known user tracking parameters "igshid" from certain URLs. ([#11580](https://github.com/brave/brave-browser/issues/11580))
 - Removed "navigator.connection". ([#20122](https://github.com/brave/brave-browser/issues/20122))
 - Fixed last connected account being selected when multiple accounts are provided for OpenSea. ([#19750](https://github.com/brave/brave-browser/issues/19750))
 - Fixed typed data signing issues with https://looksrare.org. ([#20541](https://github.com/brave/brave-browser/issues/20541))
 - Fixed backup wallet message being displayed when restoring wallet account from seed phrase. ([#19966](https://github.com/brave/brave-browser/issues/19966))
 - Fixed "My First Ad" notification not opening the correct website after rewards has been enabled. ([#19856](https://github.com/brave/brave-browser/issues/19856))
 - Fixed "Brave Wallet" icon under "Settings" being a lot larger than other icons. ([#20034](https://github.com/brave/brave-browser/issues/20034))
 - Upgraded Chromium to 98.0.4758.87. ([#20814](https://github.com/brave/brave-browser/issues/20814)) ([Changelog for 98.0.4758.87](https://chromium.googlesource.com/chromium/src/+log/97.0.4692.99..98.0.4758.87?pretty=fuller&n=1000))

## [1.34.81](https://github.com/brave/brave-browser/releases/tag/v1.34.81)

 - Upgraded Chromium to 97.0.4692.99. ([#20553](https://github.com/brave/brave-browser/issues/20553)) ([Changelog for 97.0.4692.99](https://chromium.googlesource.com/chromium/src/+log/97.0.4692.71..97.0.4692.99?pretty=fuller&n=1000))

## [1.34.80](https://github.com/brave/brave-browser/releases/tag/v1.34.80)

 - Added several new notifications to help onboard users and explain various features. ([#19888](https://github.com/brave/brave-browser/issues/19888))
 - Updated the default widget list under New Tab Page. ([#19888](https://github.com/brave/brave-browser/issues/19888))
 - Fixed autofill suggestions covering the URL bar in certain cases. ([#19575](https://github.com/brave/brave-browser/issues/19575))
 - Fixed "Backup your wallet" error message not being clickable. ([#18945](https://github.com/brave/brave-browser/issues/18945))
 - Upgraded Chromium to 97.0.4692.71. ([#20269](https://github.com/brave/brave-browser/issues/20269)) ([Changelog for 97.0.4692.71](https://chromium.googlesource.com/chromium/src/+log/96.0.4664.110..97.0.4692.71?pretty=fuller&n=1000))

## [1.33.106](https://github.com/brave/brave-browser/releases/tag/v1.33.106)

 - Added first steps of Brave Wallet (Dapps and EVM support in future releases). ([#19702](https://github.com/brave/brave-browser/issues/19702))
 - Implemented time-limited sync QR codes. ([#19550](https://github.com/brave/brave-browser/issues/19550))
 - Removed known user tracking parameters "wbraid" and "gbraid" from certain URLs. ([#18758](https://github.com/brave/brave-browser/issues/18758))
 - Upgraded Chromium to 96.0.4664.110. ([#20077](https://github.com/brave/brave-browser/issues/20077)) ([Changelog for 96.0.4664.110](https://chromium.googlesource.com/chromium/src/+log/96.0.4664.93..96.0.4664.110?pretty=fuller&n=1000))

## [1.32.115](https://github.com/brave/brave-browser/releases/tag/v1.32.115)

 - Fixed search engines not being added into Open Search. ([#19737](https://github.com/brave/brave-browser/issues/19737))
 - Upgraded Chromium to 96.0.4664.93. ([#19950](https://github.com/brave/brave-browser/issues/19950)) ([Changelog for 96.0.4664.93](https://chromium.googlesource.com/chromium/src/+log/96.0.4664.45..96.0.4664.93?pretty=fuller&n=1000))

## [1.32.112](https://github.com/brave/brave-browser/releases/tag/v1.32.112)

 - Re-enable P3A uploads if enabled by user. ([#19302](https://github.com/brave/brave-browser/issues/19302))
 - Fixed P3A being automatically enabled if disabled after upgrading in certain cases. ([#19324](https://github.com/brave/brave-browser/issues/19324))

## [1.32.106](https://github.com/brave/brave-browser/releases/tag/v1.32.106)

 - Updated autoplay to behave the same as desktop (desktop parity). ([#14142](https://github.com/brave/brave-browser/issues/14142))
 - Fixed not being able to scan sync QR code during initial setup if QR code modal was dismissed. ([#19389](https://github.com/brave/brave-browser/issues/19389))
 - Fixed sync warning modal that appears before joining sync chain not being dismissed when screen timeout is reached. ([#19483](https://github.com/brave/brave-browser/issues/19483))
 - Removed mention of "Incognito" from the "Cookie" section under "Site Settings". ([#12514](https://github.com/brave/brave-browser/issues/12514))
 - Upgraded Chromium to 96.0.4664.45. ([#19387](https://github.com/brave/brave-browser/issues/19387)) ([Changelog for 96.0.4664.45](https://chromium.googlesource.com/chromium/src/+log/95.0.4638.69..96.0.4664.45?pretty=fuller&n=1000))

## [1.31.91](https://github.com/brave/brave-browser/releases/tag/v1.31.91)

 - [Security] Clarified sync setup instructions. ([#19233](https://github.com/brave/brave-browser/issues/19233))
 - Disabled P3A temporarily due to possible instability issues and crashes in certain cases. ([#19280](https://github.com/brave/brave-browser/issues/19280))
 - Fixed inability to leave sync chain in certain cases. ([#19199](https://github.com/brave/brave-browser/issues/19199))

## [1.31.90](https://github.com/brave/brave-browser/releases/tag/v1.31.90)

 - Fixed crash when tapping on "private product analytics" under the "Welcome to Brave Browser" on-boarding screen in certain cases. ([#19135](https://github.com/brave/brave-browser/issues/19135))
 - Fixed crash when the initial "Brave Rewards" notification is displayed after enabling rewards for the first time in certain cases on Android 12 devices. ([#19149](https://github.com/brave/brave-browser/issues/19149))
 - Fixed Brave freezing and crashing in certain cases. ([#19144](https://github.com/brave/brave-browser/issues/19144))

## [1.31.88](https://github.com/brave/brave-browser/releases/tag/v1.31.88)

 - Fixed startup crash on devices running Android 12. ([#18667](https://github.com/brave/brave-browser/issues/18667))
 - Fixed startup crash when launching Brave for the first time without a network connection. ([#18825](https://github.com/brave/brave-browser/issues/18825))
 - Fixed crash when tapping on "Continue" under the "Welcome to Brave Browser" on-boarding screen in certain cases. ([#18776](https://github.com/brave/brave-browser/issues/18776))
 - Fixed incorrect search engine being set for both "Standard" and "Private" tab after making a selection under the search on-boarding screen. ([#18777](https://github.com/brave/brave-browser/issues/18777))
 - Upgraded Chromium to 95.0.4638.69. ([#19083](https://github.com/brave/brave-browser/issues/19083)) ([Changelog for 95.0.4638.69](https://chromium.googlesource.com/chromium/src/+log/95.0.4638.54..95.0.4638.69?pretty=fuller&n=1000))

## [1.31.87](https://github.com/brave/brave-browser/releases/tag/v1.31.87)

 - Added support for custom filter lists in shields via brave://adblock. ([#8107](https://github.com/brave/brave-browser/issues/8107))
 - Added support to retrieve New Tab Page background images via CRX which reduces the size of the initial app. ([#17328](https://github.com/brave/brave-browser/issues/17328))
 - Added ability to disable Chrome Sharing Hub from the share sheet via "Appearance" settings. ([#17548](https://github.com/brave/brave-browser/issues/17548))
 - Added support for Android crash reports to be uploaded to https://backtrace.io. ([#17563](https://github.com/brave/brave-browser/issues/17563))
 - Updated default search engine to Brave Search for new installations in certain regions. ([#18452](https://github.com/brave/brave-browser/issues/18452))
 - Updated website that opens in a new tab when Brave Search is selected as the default. ([#18324](https://github.com/brave/brave-browser/issues/18324))
 - Removed "Brave" from User Agent when visiting DuckDuckGo. ([#15156](https://github.com/brave/brave-browser/issues/15156))
 - Removed Uphold "x-client-partner" header. ([#18015](https://github.com/brave/brave-browser/issues/18015))
 - Removed "IdleDetection" from brave://settings/content. ([#18409](https://github.com/brave/brave-browser/issues/18409))
 - Removed known user tracking parameter "twclid" from Twitter query strings. ([#18020](https://github.com/brave/brave-browser/issues/18020))
 - Fixed "Incognito" being used instead of "Private" under "Search" settings on non-en-US locales. ([#10105](https://github.com/brave/brave-browser/issues/10105))
 - Upgraded Chromium to 95.0.4638.54. ([#18840](https://github.com/brave/brave-browser/issues/18840)) ([Changelog for 95.0.4638.54](https://chromium.googlesource.com/chromium/src/+log/94.0.4606.81..95.0.4638.54?pretty=fuller&n=1000))

## [1.30.89](https://github.com/brave/brave-browser/releases/tag/v1.30.89)

 - Upgraded Chromium to 94.0.4606.81. ([#18620](https://github.com/brave/brave-browser/issues/18620)) ([Changelog for 94.0.4606.81](https://chromium.googlesource.com/chromium/src/+log/94.0.4606.71..94.0.4606.81?pretty=fuller&n=1000))

## [1.30.87](https://github.com/brave/brave-browser/releases/tag/v1.30.87)

 - Upgraded Chromium to 94.0.4606.71. ([#18477](https://github.com/brave/brave-browser/issues/18477)) ([Changelog for 94.0.4606.71](https://chromium.googlesource.com/chromium/src/+log/94.0.4606.61..94.0.4606.71?pretty=fuller&n=1000))

## [1.30.86](https://github.com/brave/brave-browser/releases/tag/v1.30.86)

 - Added setting to "Automatically send daily usage ping to Brave" under brave://settings/privacy. ([#16583](https://github.com/brave/brave-browser/issues/16583))
 - Removed known user tracking parameters from URLs. ([#17507](https://github.com/brave/brave-browser/issues/17507), [#17452](https://github.com/brave/brave-browser/issues/17452), [#17451](https://github.com/brave/brave-browser/issues/17451))
 - Upgraded Chromium to 94.0.4606.61. ([#18333](https://github.com/brave/brave-browser/issues/18333)) ([Changelog for 94.0.4606.61](https://chromium.googlesource.com/chromium/src/+log/93.0.4577.82..94.0.4606.61?pretty=fuller&n=1000))

## [1.29.81](https://github.com/brave/brave-browser/releases/tag/v1.29.81)

 - Upgraded Chromium to 93.0.4577.82. ([#18066](https://github.com/brave/brave-browser/issues/18066)) ([Changelog for 93.0.4577.82](https://chromium.googlesource.com/chromium/src/+log/93.0.4577.63..93.0.4577.82?pretty=fuller&n=10000))

## [1.29.79](https://github.com/brave/brave-browser/releases/tag/v1.29.79)

 - Fixed issue where site settings were not being retained in certain cases. ([#17859](https://github.com/brave/brave-browser/issues/17859))

## [1.29.78](https://github.com/brave/brave-browser/releases/tag/v1.29.78)

 - Fixed Brave crash when launching Twitter App on tablets running Android 5. ([#17735](https://github.com/brave/brave-browser/issues/17735))
 - Fixed browser crash when closing private tabs after interacting with shields on private tab. ([#17657](https://github.com/brave/brave-browser/issues/17657))
 - Upgraded Chromium to 93.0.4577.63. ([#17790](https://github.com/brave/brave-browser/issues/17790)) ([Changelog for 93.0.4577.63](https://chromium.googlesource.com/chromium/src/+log/93.0.4577.58..93.0.4577.63?pretty=fuller&n=1000))

## [1.29.76](https://github.com/brave/brave-browser/releases/tag/v1.29.76)

 - Added ephemeral support to "BroadcastChannel". ([#17220](https://github.com/brave/brave-browser/issues/17220))
 - Added Uphold user ID under brave://rewards-internals to assist with rewards support. ([#16937](https://github.com/brave/brave-browser/issues/16937))
 - Updated the date of installation parameter in the stats ping to expire in 30 days. ([#17089](https://github.com/brave/brave-browser/issues/17089))
 - Removed the Brave Rewards semi-verified user wallet state which occurred in certain cases. ([#15390](https://github.com/brave/brave-browser/issues/15390))
 - Upgraded Chromium to 93.0.4577.58. ([#17668](https://github.com/brave/brave-browser/issues/17668)) ([Changelog for 93.0.4577.58](https://chromium.googlesource.com/chromium/src/+log/92.0.4515.159..93.0.4577.58?pretty=fuller&n=1000))

## [1.28.106](https://github.com/brave/brave-browser/releases/tag/v1.28.106)

 - Upgraded Chromium to 92.0.4515.159. ([#17513](https://github.com/brave/brave-browser/issues/17513)) ([Changelog for 92.0.4515.159](https://chromium.googlesource.com/chromium/src/+log/92.0.4515.131..92.0.4515.159?pretty=fuller&n=10000))

## [1.28.105](https://github.com/brave/brave-browser/releases/tag/v1.28.105)

 - Updated the custom header list to be hard-coded. ([#16455](https://github.com/brave/brave-browser/issues/16455))
 - Updated adblocking to collapse HTML elements with blocked image or iframe requests. ([#14960](https://github.com/brave/brave-browser/issues/14960))
 - Removed the mention of Gmail under the "Safe Browsing" settings. ([#16181](https://github.com/brave/brave-browser/issues/16181))
 - Fixed Brave Rewards wallet being reset after upgrading in certain cases. ([#16449](https://github.com/brave/brave-browser/issues/16449))

## [1.27.111](https://github.com/brave/brave-browser/releases/tag/v1.27.111)

 - Fixed users not being rewarded for New Tab Page Sponsored Image views in certain cases. ([#17352](https://github.com/brave/brave-browser/issues/17352))
 - Fixed ads from split groups not being displayed in certain cases. ([#17199](https://github.com/brave/brave-browser/issues/17199))
 - Fixed Brave ads database failing to upgrade in certain cases. ([#17231](https://github.com/brave/brave-browser/issues/17231))
 - Upgraded Chromium to 92.0.4515.131. ([#17306](https://github.com/brave/brave-browser/issues/17306)) ([Changelog for 92.0.4515.131](https://chromium.googlesource.com/chromium/src/+log/92.0.4515.115..92.0.4515.131?pretty=fuller&n=10000))

## [1.27.109](https://github.com/brave/brave-browser/releases/tag/v1.27.109)

 - Added new hourly options under “Maximum number of ads displayed” for Brave Ads notifications. ([#16228](https://github.com/brave/brave-browser/issues/16228))
 - Added ability to change “Block trackers & ads” to either “Standard”, “Aggressive” or “Allow all” via the shields panel. ([#16300](https://github.com/brave/brave-browser/issues/16300))
 - Added a new tab tutorial page on startup for Japan region. ([#16033](https://github.com/brave/brave-browser/issues/16033))
 - Updated default search engine for new installations in certain regions. ([#16870](https://github.com/brave/brave-browser/issues/16870))
 - Updated “Block cross-site trackers” text to “Block trackers & ads” under the shields panel. ([#16299](https://github.com/brave/brave-browser/issues/16299))
 - Updated fingerprinting protections to always return light mode when set to strict. ([#15265](https://github.com/brave/brave-browser/issues/15265))
 - Updated Brave Ads UI to show estimated pending rewards for current month only. ([#15005](https://github.com/brave/brave-browser/issues/15005))
 - Improved “Disconnected” Brave Rewards wallet state. ([#15237](https://github.com/brave/brave-browser/issues/15237))
 - Fixed “Maximum number of ads displayed” incorrectly being set to 0 after upgrade in certain cases. ([#17155](https://github.com/brave/brave-browser/issues/17155))
 - Upgraded Chromium to 92.0.4515.115. ([#17162](https://github.com/brave/brave-browser/issues/17162))

## [1.26.77](https://github.com/brave/brave-browser/releases/tag/v1.26.77)

 - Upgraded Chromium to 91.0.4472.164. ([#16977](https://github.com/brave/brave-browser/issues/16977))

## [1.26.74](https://github.com/brave/brave-browser/releases/tag/v1.26.74)

 - Renamed “Brave Search beta” to “Brave” in several locations including settings and the onboarding screen. ([#16564](https://github.com/brave/brave-browser/issues/16564))
 - Upgraded Chromium to 91.0.4472.124. ([#16600](https://github.com/brave/brave-browser/issues/16600))

## [1.26.71](https://github.com/brave/brave-browser/releases/tag/v1.26.71)

 - Fixed crash when opening links using custom tabs on certain locales. ([#16569](https://github.com/brave/brave-browser/issues/16569))
 - Fixed permission crash in certain cases when sharing stats using Brave Shields. ([#16596](https://github.com/brave/brave-browser/issues/16596))
 - Upgraded Chromium to 91.0.4472.120. ([#16576](https://github.com/brave/brave-browser/issues/16576))

## [1.26.67](https://github.com/brave/brave-browser/releases/tag/v1.26.67)

 - Added Brave Search beta to the list of available search engines. ([#15663](https://github.com/brave/brave-browser/issues/15663))
 - Added ability to clear data on exit via “Clear browsing data on exit” under settings. ([#7487](https://github.com/brave/brave-browser/issues/7487))
 - Added share button in Brave Shields to increase app virality. ([#15021](https://github.com/brave/brave-browser/issues/15021))
 - Updated brave://version to show full variation names. ([#14780](https://github.com/brave/brave-browser/issues/14780))
 - Updated the “Learn more” link on the IPFS interstitial page and under brave://settings/ipfs. ([#15829](https://github.com/brave/brave-browser/issues/15829))
 - Updated the Cloudflare privacy policy link on the Unstoppable Domains interstitial page. ([#15831](https://github.com/brave/brave-browser/issues/15831))
 - Fixed New Tab Page Sponsored Image always being opened when creating new tabs after beign added into tab groups. ([#16263](https://github.com/brave/brave-browser/issues/16263))
 - Fixed “Ask where to save files” state under “Downloads” not persisting when changed. ([#14246](https://github.com/brave/brave-browser/issues/14246))
 - Upgraded Chromium to 91.0.4472.114. ([#16489](https://github.com/brave/brave-browser/issues/16489))

## [1.25.73](https://github.com/brave/brave-browser/releases/tag/v1.25.73)

- Upgraded Chromium to 91.0.4472.106. ([#16314](https://github.com/brave/brave-browser/issues/16314))

## [1.25.72](https://github.com/brave/brave-browser/releases/tag/v1.25.72)

- Fixed $csp rules still being applied when Brave Shields has been disabled. ([#16283](https://github.com/brave/brave-browser/issues/16283))
- Upgraded Chromium to 91.0.4472.101. ([#16314](https://github.com/brave/brave-browser/issues/16314))

## [1.25.71](https://github.com/brave/brave-browser/releases/tag/v1.25.71)

 - Fixed an issue with tab-groups setting from working and re-implemented stacked tab layout. ([#16140](https://github.com/brave/brave-browser/issues/16140))
 - Upgraded Chromium to 91.0.4472.88. ([#16243](https://github.com/brave/brave-browser/issues/16243))

## [1.25.69](https://github.com/brave/brave-browser/releases/tag/v1.25.69)

 - Added support for Unstoppable Domains via Ethereum. ([#15373](https://github.com/brave/brave-browser/issues/15373))
 - Added support for “$csp” filter list rules in blocking engine. ([#14792](https://github.com/brave/brave-browser/issues/14792))
 - Removed all Japan related Brave Rewards blocks. ([#15786](https://github.com/brave/brave-browser/issues/15786))
 - Enabled logging of Brave Rewards errors by default. ([#15500](https://github.com/brave/brave-browser/issues/15500))
 - Reduced BAT threshold before being able to verify Uphold two-way user wallet from 25 to 15 BAT. ([#15196](https://github.com/brave/brave-browser/issues/15196))
 - Disabled additional parts of Google’s FLoC system. ([#14942](https://github.com/brave/brave-browser/issues/14942))
 - Disabled FirstParty Sets. ([#13098](https://github.com/brave/brave-browser/issues/13098))
 - Updated rewards wallet verification flow to match the current desktop flow. ([#13220](https://github.com/brave/brave-browser/issues/13220))
 - Updated ad notification icons to distinguish between release and beta ads. ([#7571](https://github.com/brave/brave-browser/issues/7571))
 - Updated Startpage icon under onboarding and search engine settings. ([#15515](https://github.com/brave/brave-browser/issues/15515))
 - Fixed Binance widget not being dismissed when “Buy” button is clicked and landing page is loaded. ([#14405](https://github.com/brave/brave-browser/issues/14405))
 - Fixed all tokens being displayed when viewing deposit address for a specific token. ([#15236](https://github.com/brave/brave-browser/issues/15236))
 - Fixed certain setting pages missing “X” close button. ([#10375](https://github.com/brave/brave-browser/issues/10375))
 - Fixed list of trackers being blocked under privacy report not visible when using dark theme. ([#13455](https://github.com/brave/brave-browser/issues/13455))
 - Fixed “Nothing to see here” being shown on NTP instead of favorite icons when selecting search engine from onboarding. ([#14662](https://github.com/brave/brave-browser/issues/14662))
 - Upgraded Chromium to 91.0.4472.77. ([#16054](https://github.com/brave/brave-browser/issues/16054))

## [1.24.86](https://github.com/brave/brave-browser/releases/tag/v1.24.86)

 - Fixed referral program codes not being retrieved from Google Play Store. ([#15903](https://github.com/brave/brave-browser/issues/15903))

## [1.24.85](https://github.com/brave/brave-browser/releases/tag/v1.24.85)

 - Upgraded Chromium to 90.0.4430.212. ([#15725](https://github.com/brave/brave-browser/issues/15725))

## [1.24.84](https://github.com/brave/brave-browser/releases/tag/v1.24.84)

 - Added support for Unstoppable Domains and ENS via DNS over HTTPS. ([#15159](https://github.com/brave/brave-browser/issues/15159))
 - Added support for IPFS via gateway. ([#13683](https://github.com/brave/brave-browser/issues/13683))
 - Updated 5% fee for Brave Rewards tips to only attempt to contribute 3 times per browsing session. ([#14386](https://github.com/brave/brave-browser/issues/14386))
 - Removed Chrome logo when vertically flipping opened tabs. ([#9867](https://github.com/brave/brave-browser/issues/9867))
 - Fixed “X” close button not working under “Site setting” pages. ([#12181](https://github.com/brave/brave-browser/issues/12181))
 - Fixed crash when switching to existing rewards tab in certain cases. ([#15389](https://github.com/brave/brave-browser/issues/15389))
 - Fixed Tab Groups toolbar occasionally still visible when the second last tab is closed. ([#14847](https://github.com/brave/brave-browser/issues/14847))

## [1.23.76](https://github.com/brave/brave-browser/releases/tag/v1.23.76)

 - Fixed “Estimated pending rewards” being temporarily reset to zero when server endpoint returns a non HTTP_OK status. ([#15460](https://github.com/brave/brave-browser/issues/15460))
 - Fixed artifacts appearing when using fullscreen on YouTube. ([#15548](https://github.com/brave/brave-browser/issues/15548))
 - Upgraded Chromium to 90.0.4430.93. ([#15502](https://github.com/brave/brave-browser/issues/15502))

## [1.23.74](https://github.com/brave/brave-browser/releases/tag/v1.23.74)

 - Added ability to disable Tab Groups through settings. ([#15453](https://github.com/brave/brave-browser/issues/15453))
 - Fixed issue where device information was sometimes reported in User Agent string. ([#15372](https://github.com/brave/brave-browser/issues/15372))
 - Upgraded Chromium to 90.0.4430.85. ([#15397](https://github.com/brave/brave-browser/issues/15397))

## [1.23.71](https://github.com/brave/brave-ios/releases/tag/v1.23.71)

 - Implemented verifiable advertiser conversions for Brave Ads. ([#13368](https://github.com/brave/brave-browser/issues/13368))
 - Fixed CNAME adblocking breakage in certain cases. ([#14755](https://github.com/brave/brave-browser/issues/14755))
 - Fixed Brave Shield icon being displayed in the incorrect position when using Custom Tabs. ([#9113](https://github.com/brave/brave-browser/issues/9113)) 
 - Fixed text color to improve visuals in certain reward onboarding panels. ([#13911](https://github.com/brave/brave-browser/issues/13911)) 
 - Upgraded Chromium to 90.0.4430.72. ([#15299](https://github.com/brave/brave-browser/issues/15299))

## [1.22.72](https://github.com/brave/brave-browser/releases/tag/v1.22.72)

 - Upgraded Chromium to 89.0.4389.128. ([#15270](https://github.com/brave/brave-browser/issues/15270))

## [1.22.71](https://github.com/brave/brave-browser/releases/tag/v1.22.71)

 - Fixed referral pings not initializing correctly. ([#15034](https://github.com/brave/brave-browser/issues/15034))
 - Upgraded Chromium to 89.0.4389.114. ([#15030](https://github.com/brave/brave-browser/issues/15030))

## [1.22.69](https://github.com/brave/brave-browser/releases/tag/v1.22.69)

- Improved canvas fingerprinting protections. ([#12069](https://github.com/brave/brave-browser/issues/12069))
- Enabled re-linking when Uphold wallet is connected to Brave Rewards. ([#14573](https://github.com/brave/brave-browser/issues/14573))
- Removed known Drip tracking parameters from URLs. ([#8975](https://github.com/brave/brave-browser/issues/8975))
- Updated query filter to enabled or disabled using shields toggle. ([#13242](https://github.com/brave/brave-browser/issues/13242))
- Fixed shields appearing disabled when opening links using “Open in browser” via custom tabs. ([#14645](https://github.com/brave/brave-browser/issues/14645))
- Fixed bottom toolbar appearing in landscape mode. ([#14254](https://github.com/brave/brave-browser/issues/14254))
- Fixed CNAME adblocking breakage. ([#14756](https://github.com/brave/brave-browser/issues/14756))
- Upgraded Chromium to 89.0.4389.105. ([#14891](https://github.com/brave/brave-browser/issues/14891))

## [1.21.77](https://github.com/brave/brave-browser/releases/tag/v1.21.77)

 - Updated the default number of ads per hour from 2 to 5 for new users and users who have not changed the "Maximum number of ads displayed" setting for Brave Ads. ([#14377](https://github.com/brave/brave-browser/issues/14377))
 - Fixed crash on startup in certain cases due to stats ping being called before the profile is initialized. ([#14594](https://github.com/brave/brave-browser/issues/14594))
 - Upgraded Chromium to 89.0.4389.90. ([#14694](https://github.com/brave/brave-browser/issues/14694))

## [1.21.76](https://github.com/brave/brave-browser/releases/tag/v1.21.76)

 - Fixed ads service crashing when fetching estimated earnings via rewards widget under the New Tab Page. ([#14447](https://github.com/brave/brave-browser/issues/14447))
 - Upgraded Chromium to 89.0.4389.86. ([#14579](https://github.com/brave/brave-browser/issues/14579))

## [1.21.74](https://github.com/brave/brave-browser/releases/tag/v1.21.74)

 - Fixed crash when closing tabs while "Tab Groups" is enabled via brave://flags. ([#14491](https://github.com/brave/brave-browser/issues/14491))
 - Fixed ads incorrectly displaying on https://www.reuters.com. ([#14483](https://github.com/brave/brave-browser/issues/14483))

## [1.21.73](https://github.com/brave/brave-browser/releases/tag/v1.21.73)

 - Added support for overriding default network adblocking using custom exception rules in brave://adblock. ([#5440](https://github.com/brave/brave-browser/issues/5440))
 - Added warning into Brave Sync if auto-sync has been disabled on the device. ([#11128](https://github.com/brave/brave-browser/issues/11128))
 - Implemented cosmetic filters. ([#13070](https://github.com/brave/brave-browser/issues/13070))
 - Updated referral system to skip initialization when no referral code present. ([#14428](https://github.com/brave/brave-browser/issues/14428))
 - Updated User Agent farbling to add workers support. ([#12392](https://github.com/brave/brave-browser/issues/12392))
 - Removed known Olytics tracking parameters from URLs. ([#13644](https://github.com/brave/brave-browser/issues/13644))
 - Removed known tracking parameter "wickedid" from URLs. ([#13647](https://github.com/brave/brave-browser/issues/13647))
 - Fixed default browser modal being displayed if another Brave version is already set as the default browser. ([#14078](https://github.com/brave/brave-browser/issues/14078))
 - Fixed Binance widget and autocomplete always using "en" URLs for all locales. ([#9691](https://github.com/brave/brave-browser/issues/9691))
 - Fixed cast dialog not being displayed on https://gem.cbc.ca/live/channel/ottawa. ([#13898](https://github.com/brave/brave-browser/issues/13898))
 - Upgraded Chromium to 89.0.4389.72. ([#14412](https://github.com/brave/brave-browser/issues/14412))

## [1.20.108](https://github.com/brave/brave-browser/releases/tag/v1.20.108)

 - [Security] Fixed ISP DNS leak when shields are enabled. ([#12575](https://github.com/brave/brave-browser/issues/12575))
 - Fixed onboarding tooltip being displayed when shields icon not currently in view. ([#14060](https://github.com/brave/brave-browser/issues/14060))
 - Upgraded Chromium to 88.0.4324.182. ([#14187](https://github.com/brave/brave-browser/issues/14187))

## [1.20.103](https://github.com/brave/brave-browser/releases/tag/v1.20.103)

 - Added several educational onboarding notifications for Brave Shields. ([#12209](https://github.com/brave/brave-browser/issues/12209))
 - Added onboarding for Privacy Preserving Product Analytics (P3A). ([#12723](https://github.com/brave/brave-browser/issues/12723))
 - Implemented User Agent fingerprint farbling protections. ([#12638](https://github.com/brave/brave-browser/issues/12638))
 - Updated the default browser modal. ([#12390](https://github.com/brave/brave-browser/issues/12390))
 - Updated New Tab Page background images. ([#13447](https://github.com/brave/brave-browser/issues/13447))
 - Improved UI on several onboarding modals. ([#11939](https://github.com/brave/brave-browser/issues/11939))
 - Fixed rewards onboarding under rewards panel being displayed twice. ([#13423](https://github.com/brave/brave-browser/issues/13423))
 - Fixed cases where the search engine onboarding is being displayed when URL bar not empty. ([#13392](https://github.com/brave/brave-browser/issues/13392))
 - Fixed bookmark button under the bottom toolbar opening "Edit bookmark" rather than removing bookmark. ([#14033](https://github.com/brave/brave-browser/issues/14033))

## [1.19.92](https://github.com/brave/brave-browser/releases/tag/v1.19.92)

 - Upgraded Chromium to 88.0.4324.152. ([#13969](https://github.com/brave/brave-browser/issues/13969))

## [1.19.91](https://github.com/brave/brave-browser/releases/tag/v1.19.91)

 - Removed "Homepage" under settings when bottom toolbar has been disabled which fixes a known crash. ([#13809](https://github.com/brave/brave-browser/issues/13809))
 - Improved appearance of several text strings on the rewards onboarding panels. ([#13800](https://github.com/brave/brave-browser/issues/13800))
 - Fixed several broken images on the rewards onboarding panels. ([#13749](https://github.com/brave/brave-browser/issues/13749))
 - Fixed crash when loading background images on New Tab Page in certain cases. ([#12627](https://github.com/brave/brave-browser/issues/12627))
 - Upgraded Chromium to 88.0.4324.146. ([#13900](https://github.com/brave/brave-browser/issues/13900))

## [1.19.88](https://github.com/brave/brave-browser/releases/tag/v1.19.88)

 - Added Ecosia to the default search engine list for several new regions. ([#13511](https://github.com/brave/brave-browser/issues/13511))
 - Fixed crash when updating home button state in certain cases. ([#13680](https://github.com/brave/brave-browser/issues/13680))

## [1.19.86](https://github.com/brave/brave-browser/releases/tag/v1.19.86)

 - Updated pre-populated search engine list. ([#13283](https://github.com/brave/brave-browser/issues/13283))
 - Update referrer handling for better compatibility. ([#13464](https://github.com/brave/brave-browser/issues/13464))
 - Fixed PDF files automatically downloading and opening on click. ([#12902](https://github.com/brave/brave-browser/issues/12902))
 - Fixed menu buttons not properly aligned when bottom toolbar is disabled. ([#12926](https://github.com/brave/brave-browser/issues/12926))
 - Upgraded Chromium to 88.0.4324.96. ([#13637](https://github.com/brave/brave-browser/issues/13637))

## [1.18.78](https://github.com/brave/brave-browser/releases/tag/v1.18.78)

 - Upgraded Chromium to 87.0.4280.141. ([#13399](https://github.com/brave/brave-browser/issues/13399))

## [1.18.77](https://github.com/brave/brave-browser/releases/tag/v1.18.77)

- Fixed not being able to play videos on https://www.imdb.com. ([#13101](https://github.com/brave/brave-browser/issues/13101))

## [1.18.75](https://github.com/brave/brave-browser/releases/tag/v1.18.75)

 - Added protection against private browsing detection. ([#11543](https://github.com/brave/brave-browser/issues/11543))
 - Implemented the ability to remove other devices in a sync chain. ([#11232](https://github.com/brave/brave-browser/issues/11232))
 - Implemented Brave Rewards onboarding. ([#12141](https://github.com/brave/brave-browser/issues/12141))
 - Enabled Global Privacy Control. ([#12875](https://github.com/brave/brave-browser/issues/12875))
 - Updated default search engine to Yandex for new installations in certain regions. ([#12327](https://github.com/brave/brave-browser/issues/12327))
 - Removed redundant rewards setting to address user confusion. ([#11467](https://github.com/brave/brave-browser/issues/11467))
 - Fixed issue where the number of Brave Ads delivered per day was incorrectly being limited by the ads per hour selection. ([#13215](https://github.com/brave/brave-browser/issues/13215))
 - Fixed issue where "Hide Brave Rewards Icon" setting was not being respected. ([#12533](https://github.com/brave/brave-browser/issues/12533))
 - Upgraded Chromium to 87.0.4280.101. ([#13081](https://github.com/brave/brave-browser/issues/13081))

## [1.17.75](https://github.com/brave/brave-browser/releases/tag/v1.17.75)

 - Upgraded Chromium to 87.0.4280.88. ([#13006](https://github.com/brave/brave-browser/issues/13006))

## [1.17.74](https://github.com/brave/brave-browser/releases/tag/v1.17.74)

 - Fixed only four top sites appearing under New Tab Page when background images are disabled. ([#12837](https://github.com/brave/brave-browser/issues/12837))
 - Fixed crash when "Tab Groups" or "Conditional Tab Strip" are enabled using brave://flags. ([#12809](https://github.com/brave/brave-browser/issues/12809))
 - Fixed crash under privacy report in certain cases. ([#12834](https://github.com/brave/brave-browser/issues/12834))
 - Fixed Brave stats formatting error under privacy report when reaching certain values. ([#12831](https://github.com/brave/brave-browser/issues/12831))
 - Fixed settings menu appearing on both the top and bottom when opening links using custom tabs. ([#12784](https://github.com/brave/brave-browser/issues/12784))
 - Updated "Ad notifications received this month" text under brave://rewards to "Ads received this month". ([#12719](https://github.com/brave/brave-browser/issues/12719))
 - Upgraded Chromium to 87.0.4280.67. ([#12793](https://github.com/brave/brave-browser/issues/12793))

## [1.17.72](https://github.com/brave/brave-browser/releases/tag/v1.17.72)

 - Added widgets under New Tab Page. ([#11658](https://github.com/brave/brave-browser/issues/11658))
 - Added support for CNAME adblocking. ([#11712](https://github.com/brave/brave-browser/issues/11712))
 - Implemented WebGL2 fingerprint farbling protections. ([#9189](https://github.com/brave/brave-browser/issues/9189))
 - Removed known user tracking parameter "_openstat" from query strings. ([#11579](https://github.com/brave/brave-browser/issues/11579))
 - Fixed cosmetic filters crash in certain cases. ([#12745](https://github.com/brave/brave-browser/issues/12745))
 - Fixed Startpage missing from onboarding. ([#12340](https://github.com/brave/brave-browser/issues/12340))
 - Upgraded Chromium to 87.0.4280.66. ([#12741](https://github.com/brave/brave-browser/issues/12741))

## [1.16.76](https://github.com/brave/brave-browser/releases/tag/v1.16.76)

 - Upgraded Chromium to 86.0.4240.198. ([#12645](https://github.com/brave/brave-browser/issues/12645))

## [1.16.75](https://github.com/brave/brave-browser/releases/tag/v1.16.75)

- Fixed supported links not being opened in external applications. ([#12330](https://github.com/brave/brave-browser/issues/12330))
- Changed HTTP error code Brave uses when blocking network request to better match what other browsers and tools expect, to increase compatibility with crowdsourced filter lists. ([#10063](https://github.com/brave/brave-browser/issues/10063))
- Disabled Brave notification when upgrading to a new version. ([#12507](https://github.com/brave/brave-browser/issues/12507))
- Upgraded Chromium to 86.0.4240.193. ([#12603](https://github.com/brave/brave-browser/issues/12603))

## [1.16.74](https://github.com/brave/brave-browser/releases/tag/v1.16.74)

- Fixed reCAPTCHA constantly being displayed when logging into certain websites. ([#12359](https://github.com/brave/brave-browser/issues/12359))
- Fixed crash when tapping on rewards panel after skipping onboarding. ([#12509](https://github.com/brave/brave-browser/issues/12509))
- Upgraded Chromium to 86.0.4240.185. ([#12479](https://github.com/brave/brave-browser/issues/12479))

## [1.16.70](https://github.com/brave/brave-browser/releases/tag/v1.16.70)

- Fixed "Desktop Mode". ([#11928](https://github.com/brave/brave-browser/issues/11928))
- Fixed webview crash in certain cases by using proper origin. ([#12268](https://github.com/brave/brave-browser/issues/12268))

## [1.16.68](https://github.com/brave/brave-browser/releases/tag/v1.16.68)

- Added cosmetic filtering. ([#11599](https://github.com/brave/brave-browser/issues/11599))
- Added social media blocking for Google, Twitter, LinkedIn and Facebook. ([#9536](https://github.com/brave/brave-browser/issues/9536))
- [Security] Fixed file-path for cookies as reported on HackerOne by kanytu. ([#11520](https://github.com/brave/brave-browser/issues/11520))
- [Security] Encrypted private wallet data preferences for Brave Rewards. ([#2555](https://github.com/brave/brave-browser/issues/2555))
- Updated Startpage search to give attribution to Brave. ([#12257](https://github.com/brave/brave-browser/issues/12257))
- Removed known email tracking parameters from Vero URLs. ([#11817](https://github.com/brave/brave-browser/issues/11817))
- Removed known tracking parameter "yclid" from URLs. ([#11578](https://github.com/brave/brave-browser/issues/11578))
- Removed intra-site requests from the query string filter. ([#9020](https://github.com/brave/brave-browser/issues/9020))
- Fixed breakage on sites that use "addthis" scripts in certain cases. ([#11744](https://github.com/brave/brave-browser/issues/11744))

## [1.15.76](https://github.com/brave/brave-browser/releases/tag/v1.15.76)

 - Upgraded Chromium to 86.0.4240.111. ([#12225](https://github.com/brave/brave-browser/issues/12225))

## [1.15.75](https://github.com/brave/brave-browser/releases/tag/v1.15.75)

  - Fixed "Estimated pending rewards" and "Ad notifications received this month" not being updated even though ads are being displayed in certain cases. ([#11952](https://github.com/brave/brave-browser/issues/11952))
  - Upgraded Chromium to 86.0.4240.99. ([#12124](https://github.com/brave/brave-browser/issues/12124))

## [1.15.73](https://github.com/brave/brave-browser/releases/tag/v1.15.73)

 - Added "Night Mode" under "Appearance" settings. ([#11085](https://github.com/brave/brave-browser/issues/11085))
 - Removed Chrome images from password prompt when re-logging into websites using saved passwords. ([#12018](https://github.com/brave/brave-browser/issues/12018))
 - Fixed ad landing page not loading when clicking on a silent ad notification when Brave is running in background. ([#10926](https://github.com/brave/brave-browser/issues/10926))
 - Fixed fingerprint settings not being retained in certain cases. ([#11786](https://github.com/brave/brave-browser/issues/11786))
 - Upgraded Chromium to 86.0.4240.75. ([#12021](https://github.com/brave/brave-browser/issues/12021))

## [1.14.86](https://github.com/brave/brave-browser/releases/tag/v1.14.86)

 - Upgraded Chromium to 85.0.4183.127. ([#11827](https://github.com/brave/brave-browser/issues/11827))

## [1.14.84](https://github.com/brave/brave-browser/releases/tag/v1.14.84)

 - Upgraded Chromium to 85.0.4183.121. ([#11793](https://github.com/brave/brave-browser/issues/11793))

## [1.14.83](https://github.com/brave/brave-browser/releases/tag/v1.14.83)

 - Implemented additional farbling protections for fingerprinters accessing CPU information. ([#10808](https://github.com/brave/brave-browser/issues/10808))
 - Implemented additional farbling protections for fingerprinters accessing media hardware information. ([#11271](https://github.com/brave/brave-browser/issues/11271))
 - Fixed browser still using auto-rotate even when auto-rotate has been disabled on the device. ([#11632](https://github.com/brave/brave-browser/issues/11632))
 - Fixed Brave accepting TLS 1.0 and TLS 1.1 certificates without warning users. ([#10607](https://github.com/brave/brave-browser/issues/10607))
 - Fixed WebRTC Web APIs being modified when fingerprinting protection is enabled. ([#11310](https://github.com/brave/brave-browser/issues/11310))

## [1.13.87](https://github.com/brave/brave-browser/releases/tag/v1.13.87)

 - Fixed crash when opening "Privacy Report" notification while Brave running in background. ([#11625](https://github.com/brave/brave-browser/issues/11625))
 - Fixed "Settings" menu not reachable on devices running Android 7. ([#11620](https://github.com/brave/brave-browser/issues/11620))
 - Fixed text under the location permission modal displaying "Chromium" instead of "Brave". ([#11656](https://github.com/brave/brave-browser/issues/11656))
 - Upgraded Chromium to 85.0.4183.102. ([#11621](https://github.com/brave/brave-browser/issues/11621))

## [1.13.85](https://github.com/brave/brave-browser/releases/tag/v1.13.85)

 - Implemented cross-platform promotion modal. ([#10571](https://github.com/brave/brave-browser/issues/10571))
 - Implemented "Refresh Status" button on rewards panel to check publisher status. ([#10005](https://github.com/brave/brave-browser/issues/10005))
 - Implemented new version of onboarding. ([#9555](https://github.com/brave/brave-browser/issues/9555))
 - Implemented fingerprint farbling for Plugins. ([#9435](https://github.com/brave/brave-browser/issues/9435))
 - Implemented new wallet API for Brave Rewards. ([#8428](https://github.com/brave/brave-browser/issues/8428))
 - [Security] Reduce logging as reported on HackerOne by hihouhou. ([#11456](https://github.com/brave/brave-browser/issues/11456))
 - Disabled ability to retrieve rewards logs via brave://rewards-internals and removed existing logs. ([#11260](https://github.com/brave/brave-browser/issues/11260))
 - Fixed issue where ad conversions would fail when a site uses pushState. ([#11012](https://github.com/brave/brave-browser/issues/11012))
 - Fixed not being able to open downloaded PDF and APK files. ([#11420](https://github.com/brave/brave-browser/issues/11420)
 - Fixed not being able to send links from Android to Desktop when sync is enabled. ([#11077](https://github.com/brave/brave-browser/issues/11077)
 - Upgraded Chromium to 85.0.4183.83. ([#11401](https://github.com/brave/brave-browser/issues/11401))

## [1.12.113](https://github.com/brave/brave-browser/releases/tag/v1.12.113)

 - Added Sync v2. ([#10203](https://github.com/brave/brave-browser/issues/10203))
 - Added support for state level ads delivery. ([#9200](https://github.com/brave/brave-browser/issues/9200))
 - Added the date of installation to the stats ping. ([#10061](https://github.com/brave/brave-browser/issues/10061))
 - Added farbling for WebGL API when "Fingerprinting blocking" is set to "strict". ([#10214](https://github.com/brave/brave-browser/issues/10214)) 
 - Enabled the "prefetch-privacy-changes" flag by default under brave://flags. ([#8319](https://github.com/brave/brave-browser/issues/8319))
 - Updated referrer policy to improve privacy and prevent web compatibility issues. ([#8696](https://github.com/brave/brave-browser/issues/8696))
 - Updated canvas maximum farbling to match balanced farbling. ([#11067](https://github.com/brave/brave-browser/issues/11067))
 - Updated pre-populated search engine list. ([#11089](https://github.com/brave/brave-browser/issues/11089))
 - Improved web compatibility by changing behavior of local and session storage in third-party frames to not throw an exception when storage is blocked. ([#9578](https://github.com/brave/brave-browser/issues/9758))
 - Reduced size and improved performance of the publisher list for Brave Rewards. ([#10836](https://github.com/brave/brave-browser/issues/10836))
 - Reduced the frequency at which promotions are fetched for rewards. ([#9513](https://github.com/brave/brave-browser/issues/9513))
 - Disabled ad notifications on wearables. ([#9397](https://github.com/brave/brave-browser/issues/9397)) 
 - Fixed issue where "Bat Ads Service" was running when Brave Ads were not enabled. ([#9196](https://github.com/brave/brave-browser/issues/9196))
 - Fixed crash with Brave Ads when opening a new tab in certain cases. ([#9393](https://github.com/brave/brave-browser/issues/9393))
 - Fixed issue where "Bat Ledger Service" was running when Brave Rewards was not enabled. ([#9526](https://github.com/brave/brave-browser/issues/9526))
 - Fixed file-path for cookies as reported on HackerOne by kanytu. ([#9818](https://github.com/brave/brave-browser/issues/9818))
 - Fixed "Estimated pending rewards" not being refreshed after claiming an ad grant. ([#10094](https://github.com/brave/brave-browser/issues/10094))
 - Fixed ads state being removed when Brave Ads are disabled. ([#10097](https://github.com/brave/brave-browser/issues/10097))
 - Fixed URL bar text being cleared when going into edit mode. ([#10524](https://github.com/brave/brave-browser/issues/10524))
 - Fixed ads not being enabled on clean install when enabling rewards. ([#10526](https://github.com/brave/brave-browser/issues/10526))
 - Fixed state level ads being shown on versions without support for state level ads delivery. ([#10557](https://github.com/brave/brave-browser/issues/10557))
 - Upgrade to Chromium 84.0.4147.125. ([#11153](https://github.com/brave/brave-browser/issues/11153))

## [1.11.105](https://github.com/brave/brave-browser/releases/tag/v1.11.105)

 - Implemented new Brave Shields design to match desktop. ([#9888](https://github.com/brave/brave-browser/issues/9888))
 - Implemented "Rate Brave" to capture feedback from within the app. ([#8243](https://github.com/brave/brave-browser/issues/8243))
 - Implemented Sync v1 deprecation infobar for devices that have Sync enabled. ([#10416](https://github.com/brave/brave-browser/issues/10416))
 - Added ability to view and download server error logs for Brave Rewards under "brave://rewards-internals" to improve rewards debugging. ([#10712](https://github.com/brave/brave-browser/issues/10712))
 - Fixed shields not working on custom tab when app is removed from memory. ([#10612](https://github.com/brave/brave-browser/issues/10612))
 - Updated Brave Rewards to display BAT values to three decimal places. ([#10028](https://github.com/brave/brave-browser/issues/10028))
 - Upgraded to Chromium 84.0.4147.105. ([#10732](https://github.com/brave/brave-browser/issues/10732))

## [1.10.99](https://github.com/brave/brave-browser/releases/tag/v1.10.99)

 - Fixed rewards balance appearing as "0.0 BAT" in certain cases. ([#9992](https://github.com/brave/brave-browser/issues/9992))
 - Fixed ads being shown on embedded YouTube videos. ([#10436](https://github.com/brave/brave-browser/issues/10436))
 - Upgraded to Chromium 83.0.4103.116. ([#10482](https://github.com/brave/brave-browser/issues/10482))

## [1.10.95](https://github.com/brave/brave-browser/releases/tag/v1.10.95)

 - Disabled Twitter support in the rewards panel. ([#10208](https://github.com/brave/brave-browser/issues/10208))
 - Fixed "Enable bottom toolbar" being reverted in certain cases. ([#9843](https://github.com/brave/brave-browser/issues/9843))
 - Fixed ads being shown on YouTube in certain cases. ([#10241](https://github.com/brave/brave-browser/issues/10241))
 - Fixed crash when opening new tab with Sponsored Image on certain screen resolutions. ([#10296](https://github.com/brave/brave-browser/issues/10296))

## [1.10.94](https://github.com/brave/brave-browser/releases/tag/v1.10.94)

 - Added Uphold two-way user wallets. ([#8511](https://github.com/brave/brave-browser/issues/8511))
 - Added 25 BAT threshold before being able to verify Uphold two-way user wallet. ([#9636](https://github.com/brave/brave-browser/issues/9636))
 - Fixed promotion notification not being cleared when error occurs. ([#9657](https://github.com/brave/brave-browser/issues/9657))
 - Fixed referral QR code using incorrect URL format. ([#10079](https://github.com/brave/brave-browser/issues/10079))
 - Upgraded to Chromium 83.0.4103.106. ([#10268](https://github.com/brave/brave-browser/issues/10268))

## [1.9.80](https://github.com/brave/brave-browser/releases/tag/v1.9.80)

 - Fixed default setting for "Show Brave suggested sites in autocomplete suggestions" to be off under brave://settings/appearance. ([#10131](https://github.com/brave/brave-browser/issues/10131))

## [1.9.79](https://github.com/brave/brave-browser/releases/tag/v1.9.79)

 - Implemented import/export database options for rewards. ([#9766](https://github.com/brave/brave-browser/issues/9766))
 - Added settings for "Top sites suggestions" and "Brave suggested sites". ([#9782](https://github.com/brave/brave-browser/issues/9782))
 - Added "Estimated Bandwidth Savings" stats on new tab page. ([#8845](https://github.com/brave/brave-browser/issues/8845))
 - Fixed crash on certain devices when opening custom tabs. ([#9857](https://github.com/brave/brave-browser/issues/9857))

## [1.8.112](https://github.com/brave/brave-browser/releases/tag/v1.8.112)

 - Fixed users not receiving ad promotion due to empty public key in certain cases. ([#9733](https://github.com/brave/brave-browser/issues/9733))
 - Implemented pagination for publisher list. ([#9724](https://github.com/brave/brave-browser/issues/9724))
 - Upgraded to Chromium 81.0.4044.138. ([#9736](https://github.com/brave/brave-browser/issues/9736))

## [1.8.93](https://github.com/brave/brave-browser/releases/tag/v1.8.93)

 - Added support for referral background images and top sites on the New Tab Page. ([#8217](https://github.com/brave/brave-browser/issues/8217))
 - Removed the "Telephone" permission. ([#9454](https://github.com/brave/brave-browser/issues/9454))
 - Disabled background ad notifications by default. ([#8641](https://github.com/brave/brave-browser/issues/8641))
 - Fixed Twitter displaying "Something went wrong" when toggling "Cross-site cookies blocked" using the shields panel. ([#9489](https://github.com/brave/brave-browser/issues/9489))
 - Fixed video not playing in background in certain cases. ([#9463](https://github.com/brave/brave-browser/issues/9463))
 - Fixed intermittent crash in ad confirmations due to invalid wallet. ([#9651](https://github.com/brave/brave-browser/issues/9651))
 - Fixed sponsored images on New Tab Page being cropped after rotation. ([#8892](https://github.com/brave/brave-browser/issues/8892))
 - Fixed URL overlapping tab count when using private tab and the bottom toolbar is disabled. ([#9040](https://github.com/brave/brave-browser/issues/9040))
 - Upgraded to Chromium 81.0.4044.129. ([#9734](https://github.com/brave/brave-browser/issues/9734))

## [1.7.102](https://github.com/brave/brave-browser/releases/tag/v1.7.102) 

 - Added "Open tabs in Custom Tabs" option in settings. ([#9074](https://github.com/brave/brave-browser/issues/9074))
 - Improved publisher list load time. ([#9376](https://github.com/brave/brave-browser/issues/9376))
 - Fixed ad notifications being displayed when Brave is not running. ([#7917](https://github.com/brave/brave-browser/issues/7917))
 - Fixed claiming grants issue on rewards page when there are multiple promotions available. ([#8586](https://github.com/brave/brave-browser/issues/8586))
 - Fixed custom tab being opened instead of new tab after launching PWA from home screen. ([#9037](https://github.com/brave/brave-browser/issues/9037))
 - Fixed sponsored images under New Tab Page not using defined center point. ([#9426](https://github.com/brave/brave-browser/issues/9426))
 - Fixed urlbar corners not appearing rounded when the rewards icon is disabled. ([#8983](https://github.com/brave/brave-browser/issues/8983))
 - Upgraded to Chromium 81.0.4044.122. ([#9453](https://github.com/brave/brave-browser/issues/9453))

## [1.5.131](https://github.com/brave/brave-browser/releases/tag/v1.5.131)

 - Fixed third party cookies being blocked in certain cases after upgrade causing web compatibility issues. ([#9055](https://github.com/brave/brave-browser/issues/9055))
 - Fixed Brave not closing when "Closing all tabs closes Brave" is enabled. ([#9044](https://github.com/brave/brave-browser/issues/9044))
 - Replaced Chromium incognito icons with Brave icons in private browsing. ([#9046](https://github.com/brave/brave-browser/issues/9046))

## [1.5.130](https://github.com/brave/brave-browser/releases/tag/v1.5.130)

 - Changed rewards publisher list fetch interval from 1 day to every 7 days. ([#9032](https://github.com/brave/brave-browser/issues/9032))
 - Upgraded Chromium to 80.0.3987.162. ([#9031](https://github.com/brave/brave-browser/issues/9031))

## [1.5.120](https://github.com/brave/brave-browser/releases/tag/v1.5.120)

 - Moved to new Chromium code base to improve stability and performance. ([#9052](https://github.com/brave/brave-browser/issues/9052))
