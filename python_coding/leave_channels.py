import asyncio

from telethon import TelegramClient
from telethon.tl.types import Channel
from telethon.errors import FloodWaitError


API_ID = 30563451
API_HASH = "15adf1ab55870df260f8c39c60121c6a"

client = TelegramClient("telegram_cleanup", API_ID, API_HASH)


async def main():
    channels = []

    print("\n🔍 Finding joined broadcast channels...\n")

    async for dialog in client.iter_dialogs():
        entity = dialog.entity

        # Only broadcast channels
        # Megagroups are excluded
        if isinstance(entity, Channel):
            if entity.broadcast and not entity.megagroup:
                channels.append(dialog)

    if not channels:
        print("No broadcast channels found.")
        return

    print(f"Found {len(channels)} channels:\n")

    for index, dialog in enumerate(channels, start=1):
        print(f"{index}. {dialog.name}")

    print("\n⚠️ This will leave ALL channels listed above.")
    confirmation = input('Type exactly "LEAVE ALL" to continue: ')

    if confirmation != "LEAVE ALL":
        print("\n❌ Cancelled. Nothing was changed.")
        return

    print("\n🧹 Cleanup started...\n")

    success = 0
    failed = 0

    for index, dialog in enumerate(channels, start=1):
        try:
            print(
                f"[{index}/{len(channels)}] "
                f"Leaving: {dialog.name}"
            )

            await client.delete_dialog(dialog.entity)
            success += 1

            # Small delay to reduce aggressive request bursts
            await asyncio.sleep(2)

        except FloodWaitError as error:
            print(
                f"⏳ Telegram requested a wait of "
                f"{error.seconds} seconds."
            )

            await asyncio.sleep(error.seconds + 5)

            try:
                await client.delete_dialog(dialog.entity)
                success += 1
            except Exception as retry_error:
                print(f"❌ Retry failed: {retry_error}")
                failed += 1

        except Exception as error:
            print(f"❌ Failed: {error}")
            failed += 1

    print("\n" + "=" * 40)
    print("🎉 Cleanup complete")
    print(f"Successfully left: {success}")
    print(f"Failed: {failed}")
    print("=" * 40)


with client:
    client.loop.run_until_complete(main())