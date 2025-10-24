<template>
    <aside class="flex flex-col w-64 h-screen bg-gray-900 text-white p-4">
        <!-- Logo -->
        <div class="text-2xl font-bold mb-6">
            Race timer
        </div>

        <!-- Navigation -->
        <nav class="flex flex-col gap-3">
            <a href="#" class="hover:bg-gray-700 p-2 rounded">{{ t('sidebar.dashboard') }}</a>
            <a href="#" class="hover:bg-gray-700 p-2 rounded">{{ t('sidebar.settings') }}</a>
        </nav>

        <!-- Spacer -->
        <div class="grow"></div>

        <!-- Footer -->
        <div class="text-sm text-gray-400">
            v0.1.0
        </div>
    </aside>
</template>

<script setup lang="ts">
import { useI18n } from 'vue-i18n'

const { t } = useI18n()
</script>