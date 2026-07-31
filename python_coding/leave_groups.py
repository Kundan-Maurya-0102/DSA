import asyncio
from telethon import TelegramClient
from telethon.errors import FloodWaitError

API_ID = 30563451
API_HASH = "15adf1ab55870df260f8c39c60121c6a"

client = TelegramClient(
    "telegram_full_cleanup",
    API_ID,
    API_HASH
)


async def main():
    print("Fetching all Telegram dialogs...")

    dialogs = []

    async for dialog in client.iter_dialogs():
        dialogs.append(dialog)

    total = len(dialogs)

    print(f"\nTotal dialogs found: {total}")
    print("\nThis will remove:")
    print("- Personal chats")
    print("- Bot chats")
    print("- Groups")
    print("- Supergroups")
    print("- Channels")

    confirm = input(
        '\nType exactly DELETE EVERYTHING to continue: '
    )

    if confirm != "DELETE EVERYTHING":
        print("Cancelled. Nothing was changed.")
        return

    success = 0
    failed = 0

    print("\nCleanup started...\n")

    for index, dialog in enumerate(dialogs, start=1):
        name = dialog.name or "Unknown"

        try:
            print(
                f"[{index}/{total}] Removing: {name}"
            )

            await client.delete_dialog(
                dialog.entity,
                revoke=True
            )

            success += 1

            await asyncio.sleep(1.5)

        except FloodWaitError as error:
            print(
                f"Flood wait: sleeping "
                f"{error.seconds} seconds"
            )

            await asyncio.sleep(error.seconds + 5)

            try:
                await client.delete_dialog(
                    dialog.entity,
                    revoke=True
                )

                success += 1

            except Exception as retry_error:
                print(
                    f"Retry failed for {name}: "
                    f"{retry_error}"
                )

                failed += 1

        except Exception as error:
            print(
                f"Failed: {name} | {error}"
            )

            failed += 1

    print("\n==============================")
    print("CLEANUP FINISHED")
    print(f"Removed: {success}")
    print(f"Failed: {failed}")
    print("==============================")


async def runner():
    async with client:
        await main()


asyncio.run(runner())